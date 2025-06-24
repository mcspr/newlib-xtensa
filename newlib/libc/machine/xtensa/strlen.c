#define __need_size_t
#include <stddef.h>

#include <string.h>

#include <sys/string.h>
#include <sys/pgmspace.h>

size_t
strlen(const char *s)
{
    extern size_t __fast_strlen(const char*);
    if (__pgm_expected(s))
        return strlen_P(s);

    return __fast_strlen(s);
}
