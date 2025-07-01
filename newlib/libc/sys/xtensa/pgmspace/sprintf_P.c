/* Backwards compatibility, both format and arguments are allowed to be PSTR / PROGMEM */

#include <stdarg.h>
#include <stdio.h>

int sprintf_P(char* str, const char* formatP, ...) {
    int ret;
    __gnuc_va_list arglist;
    va_start(arglist, formatP);
    ret = vsprintf(str, formatP, arglist);
    va_end(arglist);
    return ret;
}
