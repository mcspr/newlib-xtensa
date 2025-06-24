#define __need_size_t
#include <stddef.h>

#include <stdio.h>

/* STDIO function wrapper for backwards compatibility */

int vsnprintf_P(char* __s, size_t __n, const char *__fmt, va_list ap) {
    return vsnprintf(__s, __n, __fmt, ap);
}

