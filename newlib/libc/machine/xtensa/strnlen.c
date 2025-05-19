#define strnlen newlib_strnlen
#include "../../string/strnlen.c"
#undef strnlen

#include <sys/string.h>
#include <stddef.h>

size_t
strnlen(const char *s, size_t n)
{
    if (__pgm_expected(s))
        return strnlen_P(s, n);

    return newlib_strnlen(s, n);
}

