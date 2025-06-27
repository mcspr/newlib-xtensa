/* Backwards compatibility, both format and arguments are allowed to be PSTR / PROGMEM */

#include <stdio.h>

int vsnprintf_P(char* str, size_t strSize, const char* formatP, va_list ap) {
    int ret;
    ret = vsnprintf(str, strSize, formatP, ap);
    return ret;
}
