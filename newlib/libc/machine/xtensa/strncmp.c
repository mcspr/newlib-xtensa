#include <sys/string.h>

int
strncmp (const char *s1, const char *s2, size_t n)
{
    extern int rom_strncmp (const char *, const char *, size_t);
    if (__pgm_expected(s2))
        return strncmp_P (s1, s2, n);

    return rom_strncmp (s1, s2, n);
}

