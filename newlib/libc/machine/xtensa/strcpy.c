/* strcpy.c - Xtensa code to determine if source is PMEM or RAM and call appropriate strcpy routine.

  GCC is a very smart compiler, and it will, in fact, replace printf(), and its
  related functions with strcpy() calls in order to optimize speed.  This fails
  horribly when printf(PSTR("xxx")) is called since the original strcpy can't
  handle the PROGMEM source.

  See http://www.ciselant.de/projects/gcc_printf/gcc_printf.html for more info.

  There are several ways around this:
  - Adding -fno-builtin-*printf, which slows down every printf() call that was
    being optimized before.  GCC won't replace the printf() call with a strcpy()
    call, and everything will work since we now support PROGMEM strings in
    printf().
  - Create a wrapper function with the exact same signature and `__attribute__((noinline))`,
    and then use it instead of the original one.
  - Make strcpy smarter and fall back on the appropriate routine depending on
    the source parameter.  Since on the ESP8266 PROGMEM starts at 0x40000000
    this is a simple comparison.  In this case speed will be maintained.

  Note that strcpy / strncpy call may not be emitted, for example when the string is very small.
*/

#define __need_size_t
#include <stddef.h>

#include <string.h>
#undef strcpy

#include "../../sys/xtensa/pgmspace/_pgmspace.h"

char *strcpy(char *__restrict dest, const char *__restrict src)
{
    typeof(strcpy) *__rom_strcpy = (typeof(strcpy)*)(0x4000bec8);
    if (__pgm_expected(src))
        return strcpy_P(dest, src);

    return __rom_strcpy(dest, src);
}
