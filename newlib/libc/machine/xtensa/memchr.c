#define memchr newlib_memchr
#include "../../string/memchr.c"
#undef memchr

#include <sys/string.h>
#include <stddef.h>

void *
memchr(const void *s, int c, size_t n)
{
    if (__pgm_expected(s))
        return memchr_P(s, c, n);

    return newlib_memchr(s, c, n);
}
