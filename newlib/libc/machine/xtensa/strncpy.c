#define __need_size_t
#include <stddef.h>

#include <string.h>

#include <sys/string.h>
#include <sys/pgmspace.h>

char *
strncpy(char *__restrict dest, const char *__restrict src, size_t n)
{
    extern char *__fast_strncpy(char *__restrict, const char *__restrict, size_t);
    if (__pgm_expected(src))
        return strncpy_P(dest, src, n);

    return __fast_strncpy(dest, src, n);
}

