#include <sys/string.h>
#include <stddef.h>

size_t
strlen(const char *s)
{
    extern size_t rom_strlen(const char*);
    if (__pgm_expected(s))
        return strlen_P(s);

    return rom_strlen(s);
}
