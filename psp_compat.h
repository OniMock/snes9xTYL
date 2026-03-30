/*
 * PSP SDK Compatibility Header
 * Fixes for newer PSPSDK that changed API signatures.
 * Include this AFTER <pspuser.h>
 */
#ifndef _PSP_COMPAT_H_
#define _PSP_COMPAT_H_

#include <sys/time.h>
#include <psputils.h>

/*
 * Newer PSPSDK changed sceKernelLibcGettimeofday to take SceKernelTimeval*.
 * Both structs have identical layout so casting is safe.
 * Save real function, then redefine as casting macro.
 */
#ifdef __cplusplus
extern "C" {
#endif

static inline int _compat_gettimeofday(void *tv, void *tz) {
    return sceKernelLibcGettimeofday((struct SceKernelTimeval *)tv, (struct timezone *)tz);
}

#ifdef __cplusplus
}
#endif

/* Now safely redefine */
#undef sceKernelLibcGettimeofday
#define sceKernelLibcGettimeofday(tv, tz) _compat_gettimeofday((void*)(tv), (void*)(tz))

/* Fix SceIoStat member rename in newer SDK */
#ifndef st_mtime
#define st_mtime sce_st_mtime
#endif

#endif /* _PSP_COMPAT_H_ */
