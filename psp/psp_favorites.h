#ifndef __PSP_FAVORITES_H__
#define __PSP_FAVORITES_H__

/* ============================================================
 * psp_favorites.h
 * Favorites system for Snes9xTYL
 *
 * Provides a clean interface for managing a list of favorite
 * ROM paths, persisted to a plain-text file in SaveDir.
 * Compatible with PSP and PSP Go.
 * ============================================================ */

/* Maximum number of favorite ROMs that can be stored. */
#define FAV_MAX_ENTRIES  1000

/* Maximum length for a single ROM path (matches MAXPATH in filer.c). */
#define FAV_PATH_MAX     256

/* Name of the virtual "folder" shown in the root of the file browser. */
#define FAV_VIRTUAL_DIR_NAME  SJIS_STAR " FAVORITES"

/* File name (inside SaveDir) used to persist favorites. */
#define FAV_FILENAME     "favorites.fvt"

/* ---- Public API ---- */

/**
 * fav_init - Load favorites from disk into memory.
 * Must be called once at emulator start-up.
 * @param save_dir: Absolute path to the SAVES directory.
 */
void fav_init(const char *save_dir);

/**
 * fav_save - Persist the current in-memory favorites list to disk.
 * Call this whenever the list changes so the data survives a power-off.
 */
void fav_save(void);

/**
 * fav_toggle - Add the given ROM path if it is not yet a favourite,
 * or remove it if it already is.
 * @param full_path: Full absolute path to the ROM file.
 * @return  1 if the ROM was added, 0 if it was removed, -1 on error.
 */
int fav_toggle(const char *full_path);

/**
 * fav_is_favorite - Check whether a ROM path is in the favorites list.
 * @param full_path: Full absolute path to the ROM file.
 * @return  1 if favorite, 0 otherwise.
 */
int fav_is_favorite(const char *full_path);

/**
 * fav_get_count - Return how many ROMs are currently marked as favorites.
 */
int fav_get_count(void);

/**
 * fav_get_path - Return the stored path for the entry at index @idx.
 * @param idx: Zero-based index (0 .. fav_get_count()-1).
 * @return  Pointer to the path string, or NULL if out of range.
 */
const char *fav_get_path(int idx);

/**
 * fav_remove_at - Remove the favorite at position @idx.
 * Subsequent entries are shifted down.
 * @param idx: Zero-based index.
 */
void fav_remove_at(int idx);

#endif /* __PSP_FAVORITES_H__ */
