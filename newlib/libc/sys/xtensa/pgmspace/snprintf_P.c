/* Backwards compatibility, both format and arguments are allowed to be PSTR / PROGMEM */

#include <stdio.h>

int snprintf_P(char* str, size_t strSize, const char* formatP, ...) {
    int ret;
    va_list arglist;
    va_start(arglist, formatP);
    ret = vsnprintf(str, strSize, formatP, arglist);
    va_end(arglist);
    return ret;
}
