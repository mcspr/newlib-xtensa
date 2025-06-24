#include <stdio.h>
#include <stdarg.h>

/* STDIO function wrapper for backwards compatibility */

int printf_P(const char *formatP, ...) {
    int ret;
    __gnuc_va_list arglist;
    va_start(arglist, formatP);
    ret = vprintf(formatP, arglist);
    va_end(arglist);
    return ret;
}

