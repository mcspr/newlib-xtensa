#include <sys/string.h>

int
strcmp(const char *s1, const char *s2)
{
    extern int rom_strcmp(const char *, const char *);
    if (__pgm_expected(s2))
        return strcmp_P(s1, s2);

    return rom_strcmp(s1, s2);
}
