#define memccpy newlib_memccpy
#include "../../string/memccpy.c"
#undef memccpy

#include <sys/string.h>
#include <stddef.h>

void *
memccpy(void *__restrict dest, const void *__restrict src, int c, size_t n)
{
    if (__pgm_expected(src))
        return memccpy_P(dest, src, c, n);

    return newlib_memccpy(dest, src, c, n);
}
