#define __need_size_t
#include <stddef.h>

#include <stdarg.h>
#include <stdio.h>

/* STDIO function wrapper for backwards compatibility */

int snprintf_P(char* str, size_t strSize, const char *formatP, ...) {
    int ret;
    va_list arglist;
    va_start(arglist, formatP);
    ret = vsnprintf(str, strSize, formatP, arglist);
    va_end(arglist);
    return ret;
}

