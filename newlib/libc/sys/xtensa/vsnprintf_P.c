#include <machine/stdio.h>

/* STDIO function wrapper for backwards compatibility */

int vsnprintf_P(char* __s, size_t __n, const char *__fmt, __gnuc_va_list ap) {
    return vsnprintf(__s, __n, __fmt, ap);
}

