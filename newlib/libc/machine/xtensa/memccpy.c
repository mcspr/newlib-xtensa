#define _DEFAULT_SOURCE

#undef __MISC_VISIBLE
#define __MISC_VISIBLE 1
#include <string.h>

#define __need_size_t
#include <stddef.h>

#include <string.h>
#include <sys/string.h>

void *
newlib_memccpy (void *__restrict dest, const void *__restrict src, int c, size_t n)
__attribute__((visibility("hidden")));

#define memccpy newlib_memccpy
#include "../../string/memccpy.c"
#undef memccpy

void *
memccpy(void *__restrict dest, const void *__restrict src, int c, size_t n)
{
    if (__pgm_expected(src))
        return memccpy_P(dest, src, c, n);

    return newlib_memccpy(dest, src, c, n);
}
