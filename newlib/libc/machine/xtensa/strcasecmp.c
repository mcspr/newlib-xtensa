#include <strings.h>
#include <sys/string.h>

int
newlib_strcasecmp(const char *s1, const char *s2)
__attribute__((visibility("hidden")));

#define strcasecmp newlib_strcasecmp
#include "../../string/strcasecmp.c"
#undef strcasecmp

#include <sys/string.h>

int
strcasecmp(const char *s1, const char *s2)
{
    if (__pgm_expected(s2))
        return strcasecmp_P(s1, s2);

    return newlib_strcasecmp(s1, s2);
}
