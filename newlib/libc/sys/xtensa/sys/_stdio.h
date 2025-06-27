/* #defines for legacy PROGMEM _P functions which are no longer needed, but kept for backwards compatibility */

#ifndef _NEWLIB_STDIO_H
#error "must be included via <sys/stdio.h>"
#endif

#ifndef _SYS__STDIO_H_
#define _SYS__STDIO_H_

#define __need_size_t
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

int     printf_P(const char *formatP, ...) __attribute__((format(printf, 1, 2)));
int     sprintf_P(char *str, const char *formatP, ...) __attribute__((format(printf, 2, 3)));
int     snprintf_P(char *str, size_t strSize, const char *formatP, ...) __attribute__((format(printf, 3, 4)));
int     vsnprintf_P(char *str, size_t strSize, const char *formatP, __gnuc_va_list ap) __attribute__((format(printf, 3, 0)));

#ifdef __cplusplus
}
#endif

#endif
