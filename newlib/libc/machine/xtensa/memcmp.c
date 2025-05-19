#include <sys/string.h>
#include <stddef.h>

int
memcmp(const void *s1, const void *s2, size_t n)
{
    extern int rom_memcmp(const void*, const void*, size_t);
    if (__pgm_expected(s2))
        return memcmp_P(s1, s2, n);

    return rom_memcmp(s1, s2, n);
}
