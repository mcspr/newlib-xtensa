#define strncasecmp newlib_strncasecmp
#include "../../string/strncasecmp.c"
#undef strncasecmp

#include <stddef.h>
#include <sys/string.h>

int
strncasecmp(const char *s1, const char *s2, size_t n)
{
    if (__pgm_expected(s2))
        return strncasecmp_P(s1, s2, n);

    return newlib_strncasecmp(s1, s2, n);
}

