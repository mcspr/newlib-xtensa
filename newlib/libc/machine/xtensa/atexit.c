/* atexit.c, but very weak */

#include <stdlib.h>

int
atexit (void (*func)()) __attribute__((weak));

int
atexit (void (*func)())
{
  (void)func;
  return 0;
}
