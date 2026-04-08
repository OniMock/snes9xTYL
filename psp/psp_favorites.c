/* ============================================================
 * psp_favorites.c
 * Favorites system for Snes9xTYL
 *
 * Stores up to FAV_MAX_ENTRIES ROM paths in a plain-text file
 * (one path per line) inside LaunchDir. This keeps the existing
 * s9xTYL.ini untouched and avoids binary corruption risks.
 *
 * Compatible with PSP and PSP Go.
 * ============================================================ */

#include <stdio.h>
#include <string.h>

#include "psp_favorites.h"

/* ---- Internal state ---- */

/* In-memory favorites table: static allocation, no heap needed. */
static char  s_favorites[FAV_MAX_ENTRIES][FAV_PATH_MAX];
static int   s_fav_count = 0;

/* Full path to the favorites file on the memory stick. */
static char  s_fav_file[FAV_PATH_MAX];

/* Indicates whether fav_init() has been called. */
static int   s_initialized = 0;

/* ---- Helpers ---- */

/**
 * strip_newline - Remove trailing newline or carriage-return characters
 * from a string in-place.  Safe for static buffers.
 */
static void strip_newline(char *s)
{
    char *p = s + strlen(s) - 1;
    while (p >= s && (*p == '\n' || *p == '\r'))
        *p-- = '\0';
}

/* ---- Public API implementation ---- */

void fav_init(const char *save_dir)
{
    FILE *f;
    char  line[FAV_PATH_MAX];

    /* Guard: only load from disk once per session. */
    if (s_initialized)
        return;

    /* Build the path to our flat-text favorites file. */
    snprintf(s_fav_file, sizeof(s_fav_file), "%s/%s", save_dir, FAV_FILENAME);

    s_fav_count  = 0;
    s_initialized = 1;

    f = fopen(s_fav_file, "r");
    if (!f)
        return; /* No file yet; that is fine — empty list. */

    /* Read one path per line until we hit the entry cap. */
    while (s_fav_count < FAV_MAX_ENTRIES && fgets(line, sizeof(line), f)) {
        strip_newline(line);
        if (line[0] == '\0')
            continue; /* Skip blank lines. */

        strncpy(s_favorites[s_fav_count], line, FAV_PATH_MAX - 1);
        s_favorites[s_fav_count][FAV_PATH_MAX - 1] = '\0';
        s_fav_count++;
    }

    fclose(f);
}

void fav_save(void)
{
    FILE *f;
    int   i;

    if (!s_initialized)
        return;

    f = fopen(s_fav_file, "w");
    if (!f)
        return; /* Cannot write; silently ignore to avoid crashing. */

    for (i = 0; i < s_fav_count; i++)
        fprintf(f, "%s\n", s_favorites[i]);

    fclose(f);
}

int fav_toggle(const char *full_path)
{
    int i;

    if (!s_initialized || !full_path || full_path[0] == '\0')
        return -1;

    /* Search for an existing entry. */
    for (i = 0; i < s_fav_count; i++) {
        if (strcmp(s_favorites[i], full_path) == 0) {
            /* Found — remove it by shifting remaining entries down. */
            fav_remove_at(i);
            fav_save();
            return 0; /* Removed. */
        }
    }

    /* Not found — add if capacity allows. */
    if (s_fav_count >= FAV_MAX_ENTRIES)
        return -1; /* List is full. */

    strncpy(s_favorites[s_fav_count], full_path, FAV_PATH_MAX - 1);
    s_favorites[s_fav_count][FAV_PATH_MAX - 1] = '\0';
    s_fav_count++;
    fav_save();
    return 1; /* Added. */
}

int fav_is_favorite(const char *full_path)
{
    int i;
    if (!s_initialized || !full_path)
        return 0;

    for (i = 0; i < s_fav_count; i++) {
        if (strcmp(s_favorites[i], full_path) == 0)
            return 1;
    }
    return 0;
}

int fav_get_count(void)
{
    return s_fav_count;
}

const char *fav_get_path(int idx)
{
    if (idx < 0 || idx >= s_fav_count)
        return 0;
    return s_favorites[idx];
}

void fav_remove_at(int idx)
{
    int i;
    if (idx < 0 || idx >= s_fav_count)
        return;

    /* Shift all entries after idx one position to the left. */
    for (i = idx; i < s_fav_count - 1; i++)
        strncpy(s_favorites[i], s_favorites[i + 1], FAV_PATH_MAX);

    s_favorites[s_fav_count - 1][0] = '\0';
    s_fav_count--;
}
