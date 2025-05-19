// per. cores/esp8266/libc_replacements.cpp, atexit does nothing (not even exits)

#include <stdlib.h>

int __attribute__((weak))
atexit(void (*__func)(void))
{
  (void) __func;
  return 1;
}
