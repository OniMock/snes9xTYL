/* ===========================================================================
 * filer.c - PSP File Browser
 * ===========================================================================
 * Redesigned to safely handle directories with thousands of files:
 *  - No static SceIoDirent arrays (was 340 KB fixed)
 *  - Single-pass directory scan via sceIoDread
 *  - Iterative insertion sort (no recursion, safe inside a running game)
 *  - Render-only lazy loading (visible window = MAX_VISIBLE rows)
 *  - Safety cap of MAX_FILES entries per directory
 * ===========================================================================*/

#include "snes9x.h"
#include "psp.h"
#include "filer.h"
#include "homehook.h"
#include "psp_favorites.h"

/* ---- Colour constants (RGB555) ---- */
#define TITLE_COL    ((31)|(26<<5)|(31<<10))
#define PATH_COL     ((31)|(24<<5)|(28<<10))
#define FILE_COL     ((20)|(20<<5)|(31<<10))
#define DIR_COL      ((8)|(31<<5)|(8<<10))
#define SEL_COL      ((30)|(30<<5)|(31<<10))
#define SELDIR_COL   ((28)|(31<<5)|(28<<10))
#define NET_COL      (28|(4<<5)|(16<<10))
#define FAV_COL      ((31)|(28<<5)|(0<<10))
#define FAV_SEL_COL  ((31)|(31<<5)|(4<<10))
#define INFOBAR_COL  ((31)|(24<<5)|(20<<10))
#define INFOBAR_COL2 ((31)|(28<<5)|(31<<10))
#define INFOBAR_COL3 ((31)|(31<<5)|(28<<10))
#define INFOBAR_COL4 ((28)|(31<<5)|(31<<10))

/* ---- Limits ---- */
#define MAXPATH      256
#define MAX_NAME_LEN 256          /* Max filename length (matches PSP FAT limit) */
#define MAX_FILES    8192         /* Safety cap: max entries per directory scan  */
#define MAX_VISIBLE  20           /* Rows rendered on screen at once             */
#define MAX_JPEG     512          /* Max JPEG preview filenames cached            */
#define MAX_JPEG_NAME 256         /* Max JPEG filename length (= d_name size)     */

/* ---- Lightweight directory entry ---- */
typedef struct {
    char name[MAX_NAME_LEN]; /* Filename, or full path when in favorites view */
    u8   is_dir;             /* 1 = directory, 0 = file                       */
    u8   is_favorite;        /* 1 = ROM is in the favorites list               */
    u8   has_jpeg;           /* 1 = try jpeg preview, 0 = skip (already failed)*/
} DirEntry;

/* ---- Dynamic directory list ---- */
typedef struct {
    DirEntry *entries;  /* Heap-allocated array                   */
    int       count;    /* Active entries                         */
    int       capacity; /* Allocated slots                        */
} DirList;

/* ---- File type constants (matching SceIoDirent st_attr) ---- */
enum {
    TYPE_DIR  = 0x10,
    TYPE_FILE = 0x20
};

/* ---- Global state ---- */
u32 new_pad, old_pad;

static DirList g_dir;                                   /* Current dir entries  */
static char    g_jpeg_names[MAX_JPEG][MAX_JPEG_NAME];   /* Save-state JPEG list */
static int     g_jpeg_count = 0;

/* 1 when browsing the virtual Favorites folder */
int in_favorites_view = 0;

/* ---- External symbols ---- */
extern volatile int g_bSleep, g_bLoop;
extern int  os9x_cpuclock, os9x_usballowed;
extern int  os9x_lowbat;
extern char LaunchDir[256];
extern char SaveDir[256];
extern int  os9x_language;
extern int  os9x_netplay;
extern int  os9x_btn_positive_code;
extern int  os9x_btn_negative_code;
extern const char *os9x_btn_positive_str;
extern const char *os9x_btn_negative_str;
extern int  bg_img_mul;

extern int  os9x_savesnap(void);
extern int  os9x_loadsnap(char *fname, u16 *snes_image, int *height);
extern void show_background(int mul, int add);
extern void show_batteryinfo(void);
extern void show_usbinfo(void);
int psp_ExitCheck(void);

char LastPath[MAXPATH];
char FilerMsg[256];
char FileName[MAXPATH];
u16 *filer_bg;

#undef timercmp
#define timercmp(a,b,CMP) \
    (((a)->tv_sec == (b)->tv_sec) ? ((a)->tv_usec CMP (b)->tv_usec) \
                                  : ((a)->tv_sec  CMP (b)->tv_sec))

struct SceKernelTimeval filer_next, filer_cur;
extern void show_bg(u16 *bg);

/* ===========================================================================
 * String helpers
 * ===========================================================================*/

/**
 * SJISCopy - copy a filename, uppercasing ASCII while passing SJIS multi-byte
 * sequences unchanged. Used to produce sort keys for case-insensitive compare.
 *
 * @param src  Source filename (null-terminated).
 * @param dst  Destination buffer (at least MAX_NAME_LEN bytes).
 */
static void SJISCopy(const char *src, char *dst)
{
    unsigned char ca;
    int i = 0, j = 0;

    while (src[i] != '\0') {
        ca = (unsigned char)src[i];
        /* SJIS lead byte: copy two bytes verbatim */
        if (((0x81 <= ca) && (ca <= 0x9f)) || ((0xe0 <= ca) && (ca <= 0xef))) {
            dst[j++] = ca;
            i++;
            if (src[i] != '\0') {
                dst[j++] = (unsigned char)src[i];
                i++;
            }
        } else {
            /* Uppercase ASCII */
            if (ca >= 'a' && ca <= 'z') ca -= 0x20;
            dst[j++] = ca;
            i++;
        }
    }
    dst[j] = '\0';
}

/* ===========================================================================
 * File-extension detection
 * ===========================================================================*/

static const struct { const char *szExt; int nExtId; } stExtentions[] = {
    {"zip", EXT_ZIP}, {"smc", EXT_SMC}, {"sfc", EXT_SFC},
    {"fig", EXT_FIG}, {"bin", EXT_BIN}, {"1",   EXT_1},
    {"spc", EXT_SPC}, {"txt", EXT_TXT}, {NULL,  EXT_UNKNOWN}
};

/**
 * getExtId - return the extension identifier for a filename.
 *
 * @param szFilePath  Filename or full path to inspect.
 * @return  EXT_* constant, or EXT_UNKNOWN.
 */
static int getExtId(const char *szFilePath)
{
    const char *pszExt;
    int i;
    if ((pszExt = strrchr(szFilePath, '.'))) {
        pszExt++;
        for (i = 0; stExtentions[i].nExtId != EXT_UNKNOWN; i++)
            if (!strcasecmp(stExtentions[i].szExt, pszExt))
                return stExtentions[i].nExtId;
    }
    return EXT_UNKNOWN;
}

/* ===========================================================================
 * DirList memory management
 * ===========================================================================*/

/**
 * dirlist_alloc - allocate a DirList for up to `capacity` DirEntry items.
 * Uses a single malloc (no per-entry allocations) to avoid heap fragmentation.
 *
 * @param dl        List to initialise.
 * @param capacity  Number of slots to allocate.
 * @return 1 on success, 0 if malloc failed.
 */
static int dirlist_alloc(DirList *dl, int capacity)
{
    dl->entries = (DirEntry *)malloc(capacity * sizeof(DirEntry));
    if (!dl->entries) {
        dl->count = dl->capacity = 0;
        return 0;
    }
    dl->count    = 0;
    dl->capacity = capacity;
    return 1;
}

/**
 * dirlist_free - release heap memory owned by a DirList and reset its state.
 *
 * @param dl  List to free.
 */
static void dirlist_free(DirList *dl)
{
    if (dl->entries) {
        free(dl->entries);
        dl->entries = NULL;
    }
    dl->count = dl->capacity = 0;
}

/* ===========================================================================
 * Iterative sorting
 * ===========================================================================*/

/**
 * cmp_entries - compare two DirEntry objects for sort order:
 *   1. Directories sort before files.
 *   2. Favorites sort before non-favorites (skipped in favorites view).
 *   3. Case-insensitive SJIS-aware alphabetical order within groups.
 *
 * @param a  First entry.
 * @param b  Second entry.
 * @return  Negative if a < b, zero if equal, positive if a > b.
 */
static int cmp_entries(const DirEntry *a, const DirEntry *b)
{
    char fa[MAX_NAME_LEN], fb[MAX_NAME_LEN];

    /* Directories always before files */
    if (a->is_dir != b->is_dir)
        return a->is_dir ? -1 : 1;

    /* Favorites before non-favorites (not applicable inside favorites view) */
    if (!in_favorites_view && (a->is_favorite != b->is_favorite))
        return (int)b->is_favorite - (int)a->is_favorite;

    /* Case-insensitive, SJIS-aware name comparison */
    SJISCopy(a->name, fa);
    SJISCopy(b->name, fb);
    return strcmp(fa, fb);
}

/**
 * insertion_sort - iterative insertion sort on a DirEntry array.
 *
 * Chosen because:
 *  - No recursion (safe on PSP's limited kernel/game stack).
 *  - O(n) best-case when FAT returns entries already ordered.
 *  - Simple, deterministic, no extra heap needed.
 *
 * @param arr  Array of DirEntry to sort in-place.
 * @param n    Number of entries.
 */
static void insertion_sort(DirEntry *arr, int n)
{
    int i, j;
    DirEntry key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j   = i - 1;
        while (j >= 0 && cmp_entries(&arr[j], &key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* ===========================================================================
 * Directory scanning (single pass)
 * ===========================================================================*/

/**
 * dirlist_scan - read a directory once and populate g_dir.
 *
 * Design:
 *  - Allocates the full MAX_FILES block upfront (one malloc, no realloc).
 *  - Reads sceIoDread entries sequentially (no random access).
 *  - Stops when MAX_FILES is reached (with a warning shown to user).
 *  - Sorts entries with insertion_sort after closing the directory.
 *
 * @param path  Absolute path ending with '/'.
 */
static void dirlist_scan(const char *path)
{
    SceIoDirent de;
    int fd, b = 0, sort_start;
    char full_path[MAXPATH];

    /* Release previous directory */
    dirlist_free(&g_dir);

    /* Allocate one block for all entries + a few extra for pinned entries */
    if (!dirlist_alloc(&g_dir, MAX_FILES + 4)) {
        msgBoxLines(s9xTYL_msg[ERR_OUT_OF_MEM], 60);
        return;
    }

    /* ---- Pinned entries: ".." or alternate drive root ---- */
    if (path[5]) {
        /* Deeper than drive root: add parent ".." */
        DirEntry *e = &g_dir.entries[g_dir.count++];
        strncpy(e->name, "..", MAX_NAME_LEN - 1);
        e->name[MAX_NAME_LEN - 1] = '\0';
        e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;
    } else if (*path == 'm') {
        /* ms0:/ root: show ef0:/ if Memory Stick Pro Duo adapter present */
        fd = sceIoDopen("ef0:/");
        if (fd >= 0) {
            sceIoDclose(fd);
            DirEntry *e = &g_dir.entries[g_dir.count++];
            strncpy(e->name, "ef0:/", MAX_NAME_LEN - 1);
            e->name[MAX_NAME_LEN - 1] = '\0';
            e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;
            b = 1;
        }
    } else {
        /* ef0:/ root: add ms0:/ */
        DirEntry *e = &g_dir.entries[g_dir.count++];
        strncpy(e->name, "ms0:/", MAX_NAME_LEN - 1);
        e->name[MAX_NAME_LEN - 1] = '\0';
        e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;
    }

    sort_start = g_dir.count; /* everything before this is pinned, skip sort */

    /* ---- Single-pass directory read ---- */
    fd = sceIoDopen(path);
    if (fd < 0) {
        msgBoxLines(s9xTYL_msg[ERR_READ_MEMSTICK], 60);
        return;
    }

    while (g_dir.count < MAX_FILES) {
        memset(&de, 0, sizeof(de));
        if (sceIoDread(fd, &de) <= 0)
            break;

        if (de.d_name[0] == '.')
            continue;

        if (de.d_stat.st_attr & FIO_SO_IFDIR) {
            /* Directory */
            DirEntry *e = &g_dir.entries[g_dir.count++];
            snprintf(e->name, MAX_NAME_LEN, "%s/", de.d_name);
            e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;

        } else if (getExtId(de.d_name) != EXT_UNKNOWN) {
            /* Valid ROM/archive file */
            DirEntry *e = &g_dir.entries[g_dir.count];
            strncpy(e->name, de.d_name, MAX_NAME_LEN - 1);
            e->name[MAX_NAME_LEN - 1] = '\0';
            e->is_dir  = 0;
            e->has_jpeg = 1; /* optimistic; set to 0 if check fails later */

            /* Resolve favourite status once at scan time */
            snprintf(full_path, sizeof(full_path), "%s%s", path, de.d_name);
            e->is_favorite = (u8)fav_is_favorite(full_path);
            g_dir.count++;
        }

        /* Progress message every 100 entries */
        if (g_dir.count > 0 && (g_dir.count % 100) == 0) {
            char msg[128];
            snprintf(msg, sizeof(msg), s9xTYL_msg[INFO_LOADING_FILES], g_dir.count);
            msgBoxLines(msg, 0);
        }
    }

    sceIoDclose(fd);

    /* ---- Sort entries after pinned section ---- */
    int sort_count = g_dir.count - sort_start;
    if (sort_count > 1)
        insertion_sort(g_dir.entries + sort_start, sort_count);

    (void)b; /* suppress unused-variable warning */
}

/**
 * dirlist_scan_noext - scan a directory without extension filtering.
 * Used by the background/save-directory selector (getNoExtFilePath).
 *
 * @param path  Absolute path ending with '/'.
 */
static void dirlist_scan_noext(const char *path)
{
    SceIoDirent de;
    int fd, sort_start;

    dirlist_free(&g_dir);

    if (!dirlist_alloc(&g_dir, MAX_FILES + 4)) {
        msgBoxLines(s9xTYL_msg[ERR_OUT_OF_MEM], 60);
        return;
    }

    /* ---- Pinned entries ---- */
    if (path[5]) {
        DirEntry *e = &g_dir.entries[g_dir.count++];
        strncpy(e->name, "..", MAX_NAME_LEN - 1);
        e->name[MAX_NAME_LEN - 1] = '\0';
        e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;
    } else if (*path == 'm') {
        fd = sceIoDopen("ef0:/");
        if (fd >= 0) {
            sceIoDclose(fd);
            DirEntry *e = &g_dir.entries[g_dir.count++];
            strncpy(e->name, "ef0:/", MAX_NAME_LEN - 1);
            e->name[MAX_NAME_LEN - 1] = '\0';
            e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;
        }
    } else {
        DirEntry *e = &g_dir.entries[g_dir.count++];
        strncpy(e->name, "ms0:/", MAX_NAME_LEN - 1);
        e->name[MAX_NAME_LEN - 1] = '\0';
        e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;
    }

    sort_start = g_dir.count;

    fd = sceIoDopen(path);
    if (fd < 0) {
        msgBoxLines(s9xTYL_msg[ERR_READ_MEMSTICK], 60);
        return;
    }

    while (g_dir.count < MAX_FILES) {
        memset(&de, 0, sizeof(de));
        if (sceIoDread(fd, &de) <= 0)
            break;

        if (de.d_name[0] == '.')
            continue;

        DirEntry *e = &g_dir.entries[g_dir.count++];
        if (de.d_stat.st_attr & FIO_SO_IFDIR) {
            snprintf(e->name, MAX_NAME_LEN, "%s/", de.d_name);
            e->is_dir = 1;
        } else {
            strncpy(e->name, de.d_name, MAX_NAME_LEN - 1);
            e->name[MAX_NAME_LEN - 1] = '\0';
            e->is_dir = 0;
        }
        e->is_favorite = 0;
        e->has_jpeg    = 0;

        if (g_dir.count > 0 && (g_dir.count % 100) == 0) {
            char msg[128];
            snprintf(msg, sizeof(msg), s9xTYL_msg[INFO_LOADING_FILES], g_dir.count);
            msgBoxLines(msg, 0);
        }
    }

    sceIoDclose(fd);

    int sort_count = g_dir.count - sort_start;
    if (sort_count > 1)
        insertion_sort(g_dir.entries + sort_start, sort_count);
}

/* ===========================================================================
 * JPEG preview list (save-state screenshots)
 * ===========================================================================*/

/**
 * getDirJpeg - populate g_jpeg_names[] with .jpg filenames from SaveDir.
 * Called once per directory change; used to check if a screenshot exists
 * for the currently highlighted ROM without hitting the filesystem each frame.
 */
static void getDirJpeg(void)
{
    SceIoDirent de;
    int fd;

    g_jpeg_count = 0;
    fd = sceIoDopen(SaveDir);
    if (fd < 0)
        return; /* SaveDir may not exist yet — not an error */

    while (g_jpeg_count < MAX_JPEG) {
        memset(&de, 0, sizeof(de));
        if (sceIoDread(fd, &de) <= 0)
            break;

        if (de.d_name[0] == '.')
            continue;
        if (de.d_stat.st_attr & FIO_SO_IFDIR)
            continue;
        if (strstr(de.d_name, ".jpg")) {
            snprintf(g_jpeg_names[g_jpeg_count], MAX_JPEG_NAME, "%s", de.d_name);
            g_jpeg_count++;
        }
    }
    sceIoDclose(fd);
}

/* ===========================================================================
 * Favorites virtual folder
 * ===========================================================================*/

/**
 * getFilesFromFavorites - populate g_dir from the persisted favorites list.
 *
 * In favorites view, entry.name holds the full absolute ROM path.
 * Falls back to a single ".." entry if the favorites list is empty.
 */
static void getFilesFromFavorites(void)
{
    int i;
    int fav_count = fav_get_count();

    dirlist_free(&g_dir);

    /* Allocate for all favorites (minimum 2 to always have room for fallback) */
    if (!dirlist_alloc(&g_dir, fav_count + 2)) {
        /* Hard fallback — could not allocate even minimal memory */
        return;
    }

    for (i = 0; i < fav_count; i++) {
        const char *fpath = fav_get_path(i);
        if (!fpath) continue;

        DirEntry *e = &g_dir.entries[g_dir.count++];
        strncpy(e->name, fpath, MAX_NAME_LEN - 1);
        e->name[MAX_NAME_LEN - 1] = '\0';
        e->is_dir      = 0;
        e->is_favorite = 1;
        e->has_jpeg    = 1;
    }

    if (g_dir.count == 0) {
        /* No favorites: add a ".." so the list is never empty */
        DirEntry *e = &g_dir.entries[g_dir.count++];
        strncpy(e->name, "..", MAX_NAME_LEN - 1);
        e->name[MAX_NAME_LEN - 1] = '\0';
        e->is_dir = 1; e->is_favorite = 0; e->has_jpeg = 0;
    } else {
        /* Sort favorites alphabetically */
        insertion_sort(g_dir.entries, g_dir.count);
    }
}

/* ===========================================================================
 * Path validation helper
 * ===========================================================================*/

/**
 * validate_path - ensure `path` is a valid, accessible directory ending in '/'.
 * Falls back to LaunchDir (or its drive root) on failure, updating LastPath.
 */
static void validate_path(char *path, char *lp, const char *ld)
{
    int test_fd;

    if (path[0] != '\0' && path[strlen(path) - 1] != '/') {
        strcat(path, "/");
        strcpy(lp, path);
    }

    test_fd = sceIoDopen(path);
    if (test_fd < 0) {
        strcpy(path, ld);
        strcat(path, "/");
        test_fd = sceIoDopen(path);
        if (test_fd < 0) {
            /* Copy only the drive root (e.g. "ms0:/" = 5 chars).
             * memcpy avoids -Wstringop-truncation; null-term is set manually. */
            memcpy(path, ld, 5);
            path[5] = '\0';
        } else {
            sceIoDclose(test_fd);
        }
        strcpy(lp, path);
    } else {
        sceIoDclose(test_fd);
    }
}

/* ===========================================================================
 * Background rendering
 * ===========================================================================*/

static void filer_buildbg(int detailed)
{
    u16 *dst, *src;
    int i;

    if (detailed) {
        show_background(bg_img_mul,
            (os9x_lowbat ? 0x600000 : 0) | (os9x_netplay ? 100 : 0));
        if (os9x_netplay)
            pgPrint4(4, 4, 28|(4<<5)|(16<<10), 31|(28<<5)|(30<<10), "NETPLAY");
    } else {
        show_background(bg_img_mul, (os9x_lowbat ? 0x600000 : 0));
    }

    pgDrawFrame(0, 12,      479, 12,      (8<<10)|(8<<5)|8);
    pgDrawFrame(0, 13,      479, 13,      (30<<10)|(30<<5)|30);
    pgDrawFrame(0, 14,      479, 14,      (8<<10)|(8<<5)|8);
    pgDrawFrame(0, 272-15,  479, 272-15,  (8<<10)|(8<<5)|8);
    pgDrawFrame(0, 272-14,  479, 272-14,  (30<<10)|(30<<5)|30);
    pgDrawFrame(0, 272-13,  479, 272-13,  (8<<10)|(8<<5)|8);
    pgFillBoxHalfer(0, 0,       479, 11);
    pgFillBoxHalfer(0, 272-12,  479, 271);

    if (detailed) {
        pgFillBoxHalfer(260, 170, 479, 272-15);
        mh_print(270, 180, s9xTYL_msg[FILER_HELP_WINDOW1], INFOBAR_COL2);
        mh_print(270, 195, s9xTYL_msg[FILER_HELP_WINDOW2], INFOBAR_COL2);
        mh_print(270, 210, s9xTYL_msg[FILER_HELP_WINDOW3], INFOBAR_COL3);
        mh_print(270, 225, s9xTYL_msg[FILER_HELP_WINDOW4], INFOBAR_COL4);
        mh_print(270, 240, s9xTYL_msg[FILER_HELP_WINDOW5], INFOBAR_COL4);
    }

    dst = filer_bg;
    for (i = 0; i < 272; i++) {
        src = (u16 *)pgGetVramAddr(0, i);
        memcpy(dst, src, 480 * 2);
        dst += 480;
    }
}

/* ===========================================================================
 * UI Helpers - Removing Redundancy
 * ===========================================================================*/

/**
 * filer_draw_header - Draw the top path or custom message.
 */
static void filer_draw_header(const char *path, const char *msg, int bMsg)
{
    if (bMsg && msg[0]) {
        mh_print(1, 0, msg, TITLE_COL);
    } else {
        mh_print(8, 0, path, PATH_COL);
    }
}

/**
 * filer_draw_footer - Draw the bottom status bar with shortcuts.
 */
static void filer_draw_footer(int can_exit, const char *parent_name, int mode)
{
    char tmp[255];
    const char *pname = (parent_name[3] == ':') ? parent_name : s9xTYL_msg[FILER_STATUS_PARDIR];

    if (mode == 1) { /* Main browser */
        if (can_exit)
            sprintf(tmp, s9xTYL_msg[FILER_STATUS_CANEXIT1], os9x_btn_positive_str, os9x_btn_negative_str, pname);
        else
            sprintf(tmp, s9xTYL_msg[FILER_STATUS_NOEXIT1], os9x_btn_positive_str, pname);
        mh_print(4, 260, tmp, INFOBAR_COL);
    } else { /* NoExt browser */
        if (can_exit)
            sprintf(tmp, s9xTYL_msg[FILER_STATUS_CANEXIT2], os9x_btn_positive_str, os9x_btn_negative_str, pname);
        else
            sprintf(tmp, s9xTYL_msg[FILER_STATUS_NOEXIT2], os9x_btn_positive_str, pname);
        mh_print(8, 260, tmp, INFOBAR_COL);
    }
}

/**
 * filer_draw_scrollbar - Draw the sidebar scroll indicator.
 */
static void filer_draw_scrollbar(int top, int count, int rows)
{
    if (count > rows) {
        int h = 219;
        pgDrawFrame(461, 25, 462, 243, (0xd<<0)|(0xd<<5)|(0x17<<10));
        pgFillBox(465, h * top / count + 25, 477, h * (top + rows) / count + 25, (0xd<<0)|(0xd<<5)|(0x17<<10));
        pgFillBox(466, h * top / count + 26, 476, h * (top + rows) / count + 24, (0x17<<0)|(0x17<<5)|(0x1f<<10));
    }
}

/**
 * filer_render_list - Shared logic for rendering the visible file list.
 */
static void filer_render_list(int top, int sel, int rows, int smoothing, int is_main)
{
    int x = 8, y = 17, i;
    for (i = 0; i < rows; i++) {
        int idx = top + i;
        if (idx >= g_dir.count) break;

        DirEntry *e = &g_dir.entries[idx];
        char display_name[MAX_NAME_LEN + 4];
        unsigned long color;

        if (is_main) {
            int favorite = e->is_favorite;
            if (in_favorites_view) {
                if (e->is_dir) {
                    snprintf(display_name, sizeof(display_name), "  %s", s9xTYL_msg[FILER_STATUS_PARDIR]);
                    favorite = 0;
                } else {
                    const char *base = strrchr(e->name, '/');
                    base = base ? base + 1 : e->name;
                    snprintf(display_name, sizeof(display_name), SJIS_STAR " %s", base);
                }
            } else {
                if (favorite) snprintf(display_name, sizeof(display_name), SJIS_STAR " %s", e->name);
                else {
                    strncpy(display_name, e->name, sizeof(display_name) - 1);
                    display_name[sizeof(display_name) - 1] = '\0';
                }
            }
            if (idx == sel) color = favorite ? FAV_SEL_COL : SEL_COL;
            else            color = favorite ? FAV_COL     : FILE_COL;
            if (e->is_dir) color = (idx == sel) ? SELDIR_COL : DIR_COL;
        } else {
            if (idx == sel) color = SEL_COL;
            else            color = FILE_COL;
            if (e->is_dir) color = (idx == sel) ? SELDIR_COL : DIR_COL;
            strncpy(display_name, e->name, sizeof(display_name) - 1);
            display_name[sizeof(display_name) - 1] = '\0';
        }

        if (color == SEL_COL || color == SELDIR_COL || color == FAV_SEL_COL)
            mh_printSel_light(x, y, display_name, color, smoothing);
        else
            mh_print(x, y, display_name, color);
        y += 12;
    }
}

/**
 * filer_process_navigation - Common logic for UP/DOWN/LEFT/RIGHT and scroll repeat.
 */
static void filer_process_navigation(int *sel, int count, int *image_loaded)
{
    if (new_pad & PSP_CTRL_UP)   { (*sel)--; if (image_loaded) *image_loaded = 2; os9x_beep1(); }
    if (new_pad & PSP_CTRL_DOWN) { (*sel)++; if (image_loaded) *image_loaded = 2; os9x_beep1(); }
    if (new_pad & PSP_CTRL_LEFT) {
        *sel -= 10; if (*sel < 0) *sel = 0;
        if (image_loaded) *image_loaded = 2; os9x_beep1();
    }
    if (new_pad & PSP_CTRL_RIGHT) {
        *sel += 10; if (*sel >= count) *sel = count - 1;
        if (image_loaded) *image_loaded = 2; os9x_beep1();
    }
}

/**
 * filer_clamp_selection - Keep selection and scroll window within valid bounds.
 */
static void filer_clamp_selection(int *top, int *sel, int count, int rows)
{
    if (count > 0) {
        if (*top > count - rows) *top = count - rows;
        if (*top < 0)            *top = 0;
        if (*sel >= count)       *sel = 0;
        if (*sel < 0)            *sel = count - 1;
        if (*sel >= *top + rows) *top = *sel - rows + 1;
        if (*sel < *top)         *top = *sel;
    } else {
        *sel = *top = 0;
    }
}

/* ===========================================================================
 * Main ROM browser  —  getFilePath()
 * ===========================================================================*/

int getFilePath(char *out, int can_exit)
{
    static int cpt_lowbat = 0;
    int counter = 0;
    unsigned long color = RGB_WHITE;
    static int sel = 0;
    int reload_entries = 0;
    int rows = MAX_VISIBLE;
    int top = 0, x, y, h, i, bMsg = 0, up = 0;
    int pad_cnt = 0, nopress = 0, pad_cnt_acc = 0;
    int retval;
    u16 *snes_image;
    int  snesheight;
    int  image_loaded;
    int  current_smoothing;
    char path[MAXPATH], oldDir[MAXPATH], tmp[255], *p;
    int  old_netplay = os9x_netplay;

    snes_image = (u16 *)(0x44000000 + 512*272*2*2);

    /* Allocate background framebuffer */
    filer_bg = (u16 *)malloc(480 * 272 * 2);
    if (!filer_bg) {
        msgBoxLines(s9xTYL_msg[ERR_OUT_OF_MEM], 60);
        return -1;
    }

    filer_buildbg(1);

    strcpy(path, LastPath);
    validate_path(path, LastPath, LaunchDir);

    if (FilerMsg[0]) bMsg = 1;
    fav_init(LaunchDir);

    /* Load directory listing or favorites */
    if (in_favorites_view) {
        getFilesFromFavorites();
    } else {
        dirlist_scan(path);
    }

    /* Init JPEG preview state */
    getDirJpeg();
    image_loaded = 2;

    /* Restore cursor to previously selected file if any */
    if (out[0]) {
        for (i = 0; i < g_dir.count; i++) {
            if (!strcmp(out, g_dir.entries[i].name)) { sel = i; break; }
        }
    }

    pgDrawFrame(16, 16, 480-16, 272-16, 28|(28<<5)|(28<<10));
    while (get_pad()) pgWaitV();
    old_pad = 0;

    sceKernelLibcGettimeofday(&filer_next, 0);
    filer_next.tv_usec += 33 * 1000;

    /* ---- Main event loop ---- */
    for (;;) {

        /* PSP sleep/flip mode */
        if (g_bSleep) {
#ifdef ME_SOUND
            sceGuDisplay(0);
#endif
            while (g_bSleep) pgWaitVn(10);
#ifdef ME_SOUND
            sceGuDisplay(1);
#endif
        }
        if (!g_bLoop) { retval = 0; break; }

        /* Frame timing */
        for (;;) {
            sceKernelLibcGettimeofday(&filer_cur, 0);
            if (timercmp(&filer_next, &filer_cur, <)) break;
        }
        filer_next = filer_cur;
        filer_next.tv_usec += 33 * 1000;
        while (filer_next.tv_usec >= 1000000) {
            filer_next.tv_sec  += 1;
            filer_next.tv_usec -= 1000000;
        }

        counter++;
        current_smoothing = 3 + (int)roundf(sinf(counter * 3.14159f / 30.0f) * 3.0f);

        new_pad = 0;
        if (!pad_cnt) {
            new_pad = get_pad();
            nopress = !new_pad;
            if (!new_pad) pad_cnt_acc = 0;
        } else {
            pad_cnt--;
        }

        if (new_pad) {
            if (old_pad == new_pad) {
                if (pad_cnt_acc < 6) { pad_cnt = 1; pad_cnt_acc++; }
                else                   pad_cnt = 0;
            } else {
                pad_cnt_acc = 0;
                pad_cnt     = 5;
            }
            old_pad = new_pad;
        }

        if (!((cpt_lowbat++) & 127)) os9x_lowbat = scePowerIsLowBattery();

        /* Rebuild background on netplay state change */
        if (os9x_netplay != old_netplay) {
            old_netplay = os9x_netplay;
            filer_buildbg(1);
        }

        show_bg(filer_bg);

        /* ---- JPEG preview: try once per selection (idle only) ---- */
        if ((image_loaded == 2) && nopress) {
            if (!g_dir.entries[sel].is_dir && g_dir.entries[sel].has_jpeg) {
                char filename[MAXPATH + 1];
                char *fname;
                const char *src, *dotpos;
                char *dst = filename;
                int n;

                /* Build "<SaveDir>/<romname>.jpg" */
                src = SaveDir;
                while (*src) *dst++ = *src++;
                *dst++ = '/';
                fname = dst;

                src    = g_dir.entries[sel].name;
                dotpos = strrchr(g_dir.entries[sel].name, '.');
                /* Copy up to and including the dot */
                while (src <= dotpos) *dst++ = *src++;
                src = "jpg";
                while ((*dst++ = *src++));

                /* Search the cached JPEG list */
                for (n = 0; n < g_jpeg_count; n++)
                    if (!strcasecmp(fname, g_jpeg_names[n])) break;

                if (n < g_jpeg_count)
                    image_loaded = os9x_loadsnap(filename, snes_image, &snesheight);
                else
                    image_loaded = 0;

                if (!image_loaded)
                    g_dir.entries[sel].has_jpeg = 0; /* don't try again */
            }
        }

        show_batteryinfo();
        show_usbinfo();

        /* ---- L-Trigger: toggle favorite ---- */
        if ((new_pad & PSP_CTRL_LTRIGGER) && !(new_pad & PSP_CTRL_RTRIGGER)) {
            if (!g_dir.entries[sel].is_dir) {
                char fav_path[MAXPATH];
                if (in_favorites_view) {
                    /* d_name is already the full path */
                    int res = fav_toggle(g_dir.entries[sel].name);
                    if (res == 0) {
                        msgBoxLines(s9xTYL_msg[INFO_FAV_REMOVED], 20);
                        getFilesFromFavorites();
                        if (sel >= g_dir.count)
                            sel = (g_dir.count > 0 ? g_dir.count - 1 : 0);
                        image_loaded = 2;
                    }
                } else {
                    snprintf(fav_path, sizeof(fav_path), "%s%s",
                             path, g_dir.entries[sel].name);
                    int res = fav_toggle(fav_path);
                    if (res == 1) {
                        g_dir.entries[sel].is_favorite = 1;
                        msgBoxLines(s9xTYL_msg[INFO_FAV_ADDED], 20);
                    } else if (res == 0) {
                        g_dir.entries[sel].is_favorite = 0;
                        msgBoxLines(s9xTYL_msg[INFO_FAV_REMOVED], 20);
                    }
                }
                pad_cnt = 10;
            }
        }

        /* ---- Cross/O: open directory or select file ---- */
        if (new_pad & (os9x_btn_positive_code | PSP_CTRL_SQUARE)) {
            int is_square = (new_pad & PSP_CTRL_SQUARE) != 0;

            if (g_dir.entries[sel].is_dir) {
                /* Navigate into directory */
                if (!strcmp(g_dir.entries[sel].name, "..") ||
                     g_dir.entries[sel].name[3] == ':')
                {
                    up = 1;
                } else if (strcmp(g_dir.entries[sel].name, FAV_VIRTUAL_DIR_NAME) == 0) {
                    /* Enter virtual Favorites folder */
                    in_favorites_view = 1;
                    getFilesFromFavorites();
                    getDirJpeg();
                    image_loaded = 2;
                    sel = 0;
                    while (get_pad()) pgWaitV();
                } else {
                    /* Enter real subdirectory */
                    strcat(path, g_dir.entries[sel].name);
                    dirlist_scan(path);
                    getDirJpeg();
                    image_loaded = 2;
                    sel = 0;
                    while (get_pad()) pgWaitV();
                }
            } else {
                /* File selected — build output path */
                if (in_favorites_view) {
                    /* Full path already stored in name */
                    strcpy(out, g_dir.entries[sel].name);
                    strcpy(LastPath, path);
                } else {
                    strcpy(out, path);
                    strcat(out, g_dir.entries[sel].name);
                    strcpy(LastPath, path);
                }
                retval = (is_square ? 2 : 1);
                break;
            }
        } else if (new_pad & os9x_btn_negative_code) {
            if (can_exit) { retval = 0; break; }
        } else if (new_pad & PSP_CTRL_TRIANGLE) {
            up = 1;
        } else if (new_pad & (PSP_CTRL_UP|PSP_CTRL_DOWN|PSP_CTRL_LEFT|PSP_CTRL_RIGHT)) {
            filer_process_navigation(&sel, g_dir.count, &image_loaded);
        }

#ifdef HOME_HOOK
        if (readHomeButton() > 0) {
            if (inputBox(s9xTYL_msg[ASK_EXIT]))
                S9xExit();
        }
#endif

        /* Select button: delete file */
        if (new_pad & PSP_CTRL_SELECT) {
            if (inputBox(s9xTYL_msg[ASK_DELETE])) {
                msgBoxLines(s9xTYL_msg[INFO_DELETING], 0);
                strcpy(out, path);
                strcat(out, g_dir.entries[sel].name);
                strcpy(LastPath, path);
                remove(out);
                sel--;
                image_loaded = 2;
                reload_entries = 2;
            }
        } else if (new_pad & PSP_CTRL_START) {
            os9x_netplay ^= 1;
            pad_cnt = 10;
        } else if (new_pad & PSP_CTRL_RTRIGGER) {
#ifndef FW3X
            os9x_usballowed = !os9x_usballowed;
            if (os9x_usballowed) {
                msgBoxLines(s9xTYL_msg[INFO_USB_ON], 30);
                initUSBdrivers();
            } else {
                msgBoxLines(s9xTYL_msg[INFO_USB_OFF], 30);
                endUSBdrivers();
            }
#endif
        }

        /* ---- Navigate up ---- */
        if (up) {
            up = 0;
            if (in_favorites_view) {
                /* Leave virtual favorites folder */
                in_favorites_view = 0;
                dirlist_scan(path);
                getDirJpeg();
                image_loaded = 2;
                sel = 0;
            } else if (path[5]) {
                /* Go up one real directory level */
                p = strrchr(path, '/');
                *p = '\0';
                p = strrchr(path, '/');
                p++;
                strcpy(oldDir, p);
                strcat(oldDir, "/");
                *p = '\0';
                reload_entries = 1;
            } else if (g_dir.count > 0 && g_dir.entries[0].name[3] == ':') {
                /* At drive root: switch to other drive */
                strcpy(oldDir, path);
                strcpy(path, g_dir.entries[0].name);
                dirlist_scan_noext(path);
                sel = top = 0;
            }
        }

        /* ---- Reload directory (after delete or going up) ---- */
        if (reload_entries) {
            int old_sel = (reload_entries == 2) ? sel : -1;
            reload_entries = 0;
            dirlist_scan(path);
            getDirJpeg();
            image_loaded = 2;
            sel = 0;

            for (i = 0; i < g_dir.count; i++) {
                if (!strcmp(oldDir, g_dir.entries[i].name)) {
                    sel = i;
                    top = sel - 3;
                    break;
                }
            }
            if (old_sel >= 0) sel = old_sel;
        }

        /* ---- Clamp selection and scroll ---- */
        filer_clamp_selection(&top, &sel, g_dir.count, rows);

        /* ---- UI: Header, Footer, Scrollbar and List ---- */
        filer_draw_header(path, FilerMsg, bMsg);
        filer_draw_footer(can_exit, (g_dir.count > 0) ? g_dir.entries[0].name : "", 1);
        filer_draw_scrollbar(top, g_dir.count, rows);
        filer_render_list(top, sel, rows, current_smoothing, 1);

        /* ---- JPEG preview overlay ---- */
        if (image_loaded == 1) {
            int px, py, xmax = 128, ymax = snesheight / 2;
            u16 *vdst = (u16 *)pgGetVramAddr(0, 0);
            for (py = 0; py < ymax; py++) {
                for (px = 0; px < xmax; px++) {
                    int c00 = snes_image[(py*2)   * 256 + (px*2)];
                    int c01 = snes_image[(py*2+1)  * 256 + (px*2)];
                    int c10 = snes_image[(py*2)   * 256 + (px*2+1)];
                    int c11 = snes_image[(py*2+1)  * 256 + (px*2+1)];
                    int col =
                        ((((((c00>>10)&31)+((c01>>10)&31)+
                             ((c10>>10)&31)+((c11>>10)&31))>>2)<<10) |
                         (((((c00>>5 )&31)+((c01>>5 )&31)+
                             ((c10>>5 )&31)+((c11>>5 )&31))>>2)<<5)  |
                         ((((c00&31)+(c01&31)+(c10&31)+(c11&31))>>2)));
                    vdst[(py + 17) * 512 + px + 480 - xmax - 24] = (u16)col;
                }
            }
            pgDrawFrame(480-xmax-24-2, 17-2, 480-24+2, 17+ymax+2,
                        12|(12<<5)|(12<<10));
            pgDrawFrame(480-xmax-24-1, 17-1, 480-24+1, 17+ymax+1,
                        30|(30<<5)|(30<<10));
        }

        pgScreenFlipV2();
        if (psp_ExitCheck()) { retval = -1; break; }
    }

    while (get_pad()) pgWaitV();

    /* Release the flat background framebuffer */
    free(filer_bg);
    filer_bg = NULL;

    /* Release directory list memory */
    dirlist_free(&g_dir);

    return retval;
}

/* ===========================================================================
 * Save-directory / background browser  —  getNoExtFilePath()
 * ===========================================================================*/

int getNoExtFilePath(char *out, int can_exit)
{
    static int cpt_lowbat = 0;
    static int sel = 0;
    int rows = MAX_VISIBLE;
    int top = 0, h, i, bMsg = 0, up = 0;
    int pad_cnt = 5, pad_cnt_acc = 0;
    int retval;
    int current_smoothing;
    int cnt = 0;
    char path[MAXPATH], oldDir[MAXPATH], tmp[255], *p;

    filer_bg = (u16 *)malloc(480 * 272 * 2);
    if (!filer_bg) {
        msgBoxLines(s9xTYL_msg[ERR_OUT_OF_MEM], 60);
        return -1;
    }
    filer_buildbg(0);

    strcpy(path, LastPath);
    validate_path(path, LastPath, LaunchDir);

    if (FilerMsg[0]) bMsg = 1;

    dirlist_scan_noext(path);

    pgDrawFrame(16, 16, 480-16, 272-16, 28|(28<<5)|(28<<10));
    while (get_pad()) pgWaitV();
    old_pad = 0;

    sceKernelLibcGettimeofday(&filer_next, 0);
    filer_next.tv_usec += 33 * 1000;

    for (;;) {
        current_smoothing = 3 + (int)roundf(sinf(cnt * 3.14159f / 30.0f) * 3.0f);
        cnt++;

        if (g_bSleep) {
#ifdef ME_SOUND
            sceGuDisplay(0);
#endif
            while (g_bSleep) pgWaitVn(10);
#ifdef ME_SOUND
            sceGuDisplay(1);
#endif
        }
        if (!g_bLoop) { retval = 0; break; }

        for (;;) {
            sceKernelLibcGettimeofday(&filer_cur, 0);
            if (timercmp(&filer_next, &filer_cur, <)) break;
        }
        filer_next = filer_cur;
        filer_next.tv_usec += 33 * 1000;
        while (filer_next.tv_usec >= 1000000) {
            filer_next.tv_sec  += 1;
            filer_next.tv_usec -= 1000000;
        }

        if (!((cpt_lowbat++) & 127)) os9x_lowbat = scePowerIsLowBattery();

        show_bg(filer_bg);
        show_batteryinfo();
        show_usbinfo();

        new_pad = 0;
        if (!pad_cnt) {
            new_pad = get_pad();
            if (!new_pad) pad_cnt_acc = 0;
        } else {
            pad_cnt--;
        }

        if (new_pad) {
            if (old_pad == new_pad) {
                if (pad_cnt_acc < 6) { pad_cnt = 1; pad_cnt_acc++; }
                else                   pad_cnt = 0;
            } else {
                pad_cnt_acc = 0;
                pad_cnt     = 5;
            }
            old_pad = new_pad;
        }

        if (new_pad & os9x_btn_positive_code) {
            if (g_dir.entries[sel].is_dir) {
                if (!strcmp(g_dir.entries[sel].name, "..") ||
                     g_dir.entries[sel].name[3] == ':')
                {
                    up = 1;
                } else {
                    strcat(path, g_dir.entries[sel].name);
                    dirlist_scan_noext(path);
                    sel = 0;
                    while (get_pad()) pgWaitV();
                }
            } else {
                strcpy(out, path);
                strcat(out, g_dir.entries[sel].name);
                retval = 1;
                break;
            }
        } else if (new_pad & os9x_btn_negative_code) {
            if (can_exit) { retval = 0; break; }
        } else if (new_pad & PSP_CTRL_TRIANGLE) {
            up = 1; os9x_beep1();
        } else if (new_pad & (PSP_CTRL_UP|PSP_CTRL_DOWN|PSP_CTRL_LEFT|PSP_CTRL_RIGHT)) {
            filer_process_navigation(&sel, g_dir.count, NULL);
        } else if (new_pad & PSP_CTRL_LTRIGGER) {
            if (new_pad & PSP_CTRL_RTRIGGER) {
                if (inputBox(s9xTYL_msg[ASK_EXIT]))
                    S9xExit();
            }
        } else if (new_pad & PSP_CTRL_RTRIGGER) {
#ifndef FW3X
            os9x_usballowed = !os9x_usballowed;
            if (os9x_usballowed) initUSBdrivers();
            else                 endUSBdrivers();
#endif
        }

        if (up) {
            if (path[5]) {
                p = strrchr(path, '/');
                *p = '\0';
                p = strrchr(path, '/');
                p++;
                strcpy(oldDir, p);
                strcat(oldDir, "/");
                *p = '\0';
                dirlist_scan_noext(path);
                sel = 0;
                for (i = 0; i < g_dir.count; i++) {
                    if (!strcmp(oldDir, g_dir.entries[i].name)) {
                        sel = i;
                        top = sel - 3;
                        break;
                    }
                }
            } else if (g_dir.count > 0 && g_dir.entries[0].name[3] == ':') {
                strcpy(oldDir, path);
                strcpy(path, g_dir.entries[0].name);
                dirlist_scan_noext(path);
                sel = top = 0;
            }
            up = 0;
        }

        /* ---- Clamp selection and scroll ---- */
        filer_clamp_selection(&top, &sel, g_dir.count, rows);

        /* ---- UI: Header, Footer, Scrollbar and List ---- */
        filer_draw_header(path, FilerMsg, bMsg);
        filer_draw_footer(can_exit, (g_dir.count > 0) ? g_dir.entries[0].name : "", 2);
        filer_draw_scrollbar(top, g_dir.count, rows);
        filer_render_list(top, sel, rows, current_smoothing, 0);

        pgScreenFlipV2();
        if (psp_ExitCheck()) { retval = -1; break; }
    }

    while (get_pad()) pgWaitV();

    free(filer_bg);
    filer_bg = NULL;

    /* Release directory list; reset favorites view flag */
    dirlist_free(&g_dir);
    in_favorites_view = 0;

    return retval;
}

/* ===========================================================================
 * filer_init - initialise the filer with a title message and starting path.
 * ===========================================================================*/

/**
 * filer_init - set the filer's display message and initial path before opening.
 *
 * @param msg   Title message string (or "" for path display).
 * @param path  Initial directory path.
 * @return Always 1 (success).
 */
int filer_init(const char *msg, const char *path)
{
    if (msg) strcpy(FilerMsg, msg);
    else FilerMsg[0] = '\0';

    strcpy(LastPath, path);
    /* Zero-initialise the directory list but do not allocate yet */
    memset(&g_dir, 0, sizeof(g_dir));
    return 1;
}
