/*
  Prefer our wrapper functions when address space does not support unaligned reads
  Branch to either ROM or newlib implementation otherwise
*/

#include <sys/string.h>
#include <stdbool.h>
#include <stdint.h>

#include <xtensa/config/core-isa.h>

static inline bool __xtensa_force_aligned(const void *p)
{
    return ((uintptr_t)p & (uintptr_t)XCHAL_INSTRAM0_VADDR) > 0;
}

void *memchr(const void *s, int c, size_t n)
{
    extern void *newlib_memchr(const void*, int, size_t);
    if (__xtensa_force_aligned(s))
        return memchr_P(s, c, n);

    return newlib_memchr(s, c, n);
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    extern int rom_memcmp(const void*, const void*, size_t);
    if (__xtensa_force_aligned(s2))
        return memcmp_P(s1, s2, n);

    return rom_memcmp(s1, s2, n);
}

void *memcpy(void *__restrict dest, const void *__restrict src, size_t n)
{
    extern void *rom_memcpy(void *__restrict, const void *__restrict, size_t);
    if (__xtensa_force_aligned(src))
        return memcpy_P(dest, src, n);

    return rom_memcpy(dest, src, n);
}

void *memmove(void *dest, const void *src, size_t n)
{
    extern void *rom_memmove(void *__restrict, const void *__restrict, size_t);
    if (__xtensa_force_aligned(src) && !__xtensa_force_aligned(dest))
        return memcpy_P(dest, src, n);

    return rom_memmove(dest, src, n);
}

char *strcat(char *__restrict dest, const char *__restrict src)
{
    extern void *newlib_strcat(char *__restrict, const char *__restrict);
    if (__xtensa_force_aligned(src))
        return strcat_P(dest, src);

    return newlib_strcat(dest, src);
}

int strcmp(const char *s1, const char *s2)
{
    extern int rom_strcmp(const char *, const char *);
    if (__xtensa_force_aligned(s2))
        return strcmp_P(s1, s2);

    return rom_strcmp(s1, s2);
}

char *strcpy(char *__restrict dest, const char *__restrict src)
{
    extern char *__fast_strcpy(char *__restrict, const char *__restrict);
    if (__xtensa_force_aligned(src))
        return strcpy_P(dest, src);

    return __fast_strcpy(dest, src);
}

char *strncpy(char *__restrict dest, const char *__restrict src, size_t n)
{
    extern char *__fast_strncpy(char *__restrict, const char *__restrict, size_t);
    if (__xtensa_force_aligned(src))
        return strncpy_P(dest, src, n);

    return __fast_strncpy(dest, src, n);
}

size_t strlen(const char *s)
{
    extern size_t rom_strlen(const char*);
    if (__xtensa_force_aligned(s))
        return strlen_P(s);

    return rom_strlen(s);
}

char *strncat(char *dest, const char *__restrict src, size_t n)
{
    extern void *newlib_strncat(char*, const char *__restrict, size_t);
    if (__xtensa_force_aligned(src))
        return strncat_P(dest, src, n);

    return newlib_strncat(dest, src, n);
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    extern int rom_strncmp(const char *, const char *, size_t);
    if (__xtensa_force_aligned(s2))
        return strncmp_P(s1, s2, n);

    return rom_strncmp(s1, s2, n);
}

char *strstr(const char *haystack, const char *needle)
{
    extern char *rom_strstr(const char *, const char *);
    if (__xtensa_force_aligned(needle))
        return strstr_P(haystack, needle);

    return rom_strstr(haystack, needle);
}

char *strnstr(const char *haystack, const char *needle, size_t haystacklen)
{
    extern char *newlib_strnstr(const char *, const char *, size_t);
    if (__xtensa_force_aligned(needle))
        return strnstr_P(haystack, needle, haystacklen);

    return newlib_strnstr(haystack, needle, haystacklen);
}

void *memccpy(void *__restrict dest, const void *__restrict src, int c, size_t n)
{
    extern void *newlib_memccpy(void *__restrict, const void *__restrict, int, size_t);
    if (__xtensa_force_aligned(src))
        return memccpy_P(dest, src, c, n);

    return newlib_memccpy(dest, src, c, n);
}

void *memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen)
{
    extern void *newlib_memmem(const void*, size_t, const void*, size_t);
    if (__xtensa_force_aligned(needle))
        return memmem_P(haystack, haystacklen, needle, needlelen);

    return newlib_memmem(haystack, haystacklen, needle, needlelen);
}

size_t strnlen(const char *s, size_t n)
{
    extern size_t newlib_strnlen(const char*, size_t);
    if (__xtensa_force_aligned(s))
        return strnlen_P(s, n);

    return newlib_strnlen(s, n);
}

int strncasecmp(const char *s1, const char *s2, size_t n)
{
    extern int newlib_strncasecmp(const char *, const char *, size_t);
    if (__xtensa_force_aligned(s2))
        return strncasecmp_P(s1, s2, n);

    return newlib_strncasecmp(s1, s2, n);
}

int strcasecmp(const char *s1, const char *s2)
{
    extern int newlib_strcasecmp(const char *, const char *);
    if (__xtensa_force_aligned(s2))
        return strcasecmp_P(s1, s2);

    return newlib_strcasecmp(s1, s2);
}
