#define _GNU_SOURCE
#include <stddef.h>

#include <string.h>
#include <sys/string.h>
#include <sys/pgmspace.h>

#undef mempcpy

void *
mempcpy(void *__restrict dest, const void *__restrict src, size_t n)
{
    extern void *__fast_memcpy(void *__restrict, const void *__restrict, size_t);
    if (__pgm_expected(src))
        return (unsigned char *)memcpy_P(dest, src, n) + n;

    return (unsigned char *)__fast_memcpy(dest, src, n) + n;
}
