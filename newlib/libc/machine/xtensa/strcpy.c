#include <sys/string.h>

char *
strcpy(char *__restrict dest, const char *__restrict src)
{
    extern char *__fast_strcpy(char *__restrict, const char *__restrict);
    if (__pgm_expected(src))
        return strcpy_P(dest, src);

    return __fast_strcpy(dest, src);
}
