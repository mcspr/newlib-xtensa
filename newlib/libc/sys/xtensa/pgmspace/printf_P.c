/* Backwards compatibility, both format and arguments are allowed to be PSTR / PROGMEM */

#include <stdarg.h>
#include <stdio.h>

int printf_P(const char* formatP, ...) {
    int ret;
    __gnuc_va_list arglist;
    va_start(arglist, formatP);
    ret = vprintf(formatP, arglist);
    va_end(arglist);
    return ret;
}

