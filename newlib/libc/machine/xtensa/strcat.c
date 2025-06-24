#include <string.h>
#undef strcat

char *
newlib_strcat(char *__restrict, const char *__restrict)
__attribute__((visibility("hidden")));

#define strcat newlib_strcat
#include "../../string/strcat.c"
#undef strcat

#include <sys/string.h>
#include <sys/pgmspace.h>

char *
strcat(char *__restrict dest, const char *__restrict src)
{
    if (__pgm_expected(src))
        return strcat_P(dest, src);

    return newlib_strcat(dest, src);
}
