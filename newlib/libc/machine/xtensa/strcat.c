#define strcat newlib_strcat
#include "../../string/strcat.c"
#undef strcat

#include <sys/string.h>

char *
strcat(char *__restrict dest, const char *__restrict src)
{
    if (__pgm_expected(src))
        return strcat_P(dest, src);

    return newlib_strcat(dest, src);
}
