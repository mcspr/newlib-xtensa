#define __need_size_t
#include <stddef.h>

#include <string.h>
#undef memmove

#include <sys/string.h>
#include <sys/pgmspace.h>

void *
memmove(void *dest, const void *src, size_t n)
{
    extern void *rom_memmove(void *__restrict, const void *__restrict, size_t);
    if (__pgm_expected(src) && !__pgm_expected(dest))
        return memcpy_P(dest, src, n);

    return rom_memmove(dest, src, n);
}
