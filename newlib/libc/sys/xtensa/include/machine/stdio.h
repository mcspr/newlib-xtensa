#ifndef _MACHINE_STDIO_H_
#define _MACHINE_STDIO_H_

#include <_ansi.h>

#define __need_size_t
#include <stddef.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/* legacy PROGMEM _P functions. no longer needed, but kept for backwards compatibility reasons */

int     printf_P(const char *formatP, ...)
    _ATTRIBUTE ((__format__ (__printf__, 1, 2)));
int     sprintf_P(char *str, const char *formatP, ...)
    _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int     snprintf_P(char *str, size_t strSize, const char *formatP, ...)
    _ATTRIBUTE ((__format__ (__printf__, 3, 4)));
int     vsnprintf_P(char *str, size_t strSize, const char *formatP, va_list)
    _ATTRIBUTE ((__format__ (__printf__, 3, 0)));

#ifdef __cplusplus
}
#endif

#endif
