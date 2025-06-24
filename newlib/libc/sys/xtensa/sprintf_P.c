#include <machine/stdio.h>

#include <stdarg.h>
#include <stdio.h>

/* STDIO function wrapper for backwards compatibility */

int sprintf_P(char* str, const char *formatP, ...) {
    int ret;
    __gnuc_va_list arglist;
    va_start(arglist, formatP);
    ret = vsprintf(str, formatP, arglist);
    va_end(arglist);
    return ret;
}
