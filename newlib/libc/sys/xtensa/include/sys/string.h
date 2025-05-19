/*
 * sys/string.h
 *
 * Xtensa custom PROGMEM string function definitions
 */

#ifndef _SYS_STRING_H_
#define	_SYS_STRING_H_

#include "_ansi.h"
#include <sys/reent.h>
#include <sys/cdefs.h>
#include <sys/features.h>

#define __need_size_t
#define __need_NULL
#include <stddef.h>

#define SIZE_IRRELEVANT 0x7fffffff

#ifdef __cplusplus
extern "C" {
#endif

int	memcmp_P(const void *, const void *, size_t);
void *memmem_P(const void *, size_t, const void *, size_t);
void *memccpy_P(void * __restrict, const void * __restrict, int, size_t);
void *memchr_P(const void *, int, size_t);

void *memcpy_P(void * __restrict, const void * __restrict, size_t);
static inline void *memmove_P(void *__restrict dest, const void *__restrict src, size_t n)
{
    return memcpy_P(dest, src, n);
}

char	*strncpy_P(char *__restrict, const char *__restrict, size_t);
static inline char *strcpy_P(char *__restrict dest, const char *__restrict src)
{
    return strncpy_P(dest, src, SIZE_IRRELEVANT);
}

char	*strncat_P(char *__restrict, const char *__restrict, size_t);
static inline char *strcat_P(char *__restrict dest, const char *__restrict src)
{
    return strncat_P(dest, src, SIZE_IRRELEVANT);
}

int	strncmp_P(const char *, const char *, size_t);
static inline int strcmp_P(const char *str1, const char *str2)
{
    return strncmp_P(str1, str2, SIZE_IRRELEVANT);
}

int	strncasecmp_P(const char *, const char *, size_t);
static inline int strcasecmp_P(const char *str1, const char *str2)
{
    return strncasecmp_P(str1, str2, SIZE_IRRELEVANT);
}

size_t	strnlen_P(const char *, size_t);
static inline size_t strlen_P(const char *s)
{
    return strnlen_P(s, SIZE_IRRELEVANT);
}

char	*strnstr_P(const char *, const char *, size_t);
char	*strstr_P(const char *, const char *);

#ifdef __cplusplus
}
#endif


#endif /* _SYS_STRING_H_ */
