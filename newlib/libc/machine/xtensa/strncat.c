#define strncat newlib_strncat
#include "../../string/strncat.c"
#undef strncat

#include <sys/string.h>

char *
strncat(char *dest, const char *__restrict src, size_t n)
{
    if (__pgm_expected(src))
        return strncat_P(dest, src, n);

    return newlib_strncat(dest, src, n);
}
