/* Backwards compatibility, both format and arguments are allowed to be PSTR / PROGMEM */

#define __need_size_t
#include <stddef.h>

#include <stdarg.h>
#include <stdio.h>

int vsnprintf_P(char* str, size_t strSize, const char* formatP, __gnuc_va_list ap) {
    int ret;
    ret = vsnprintf(str, strSize, formatP, ap);
    return ret;
}
