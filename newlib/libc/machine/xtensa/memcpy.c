#include <sys/string.h>
#include <stddef.h>

void *
memcpy(void *__restrict dest, const void *__restrict src, size_t n)
{
    extern void *rom_memcpy(void *__restrict, const void *__restrict, size_t);
    if (__pgm_expected(src))
        return memcpy_P(dest, src, n);

    return rom_memcpy(dest, src, n);
}
