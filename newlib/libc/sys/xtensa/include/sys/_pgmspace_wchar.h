/* Accessor for wchar_t data which always uses 32bit aligned load */

#pragma once

#include <stdint.h>

#ifdef WCHAR_MAX

/* 4 */
#if WCHAR_MAX > 0xffff
    #define pgm_read_wchar(addr) (*addr)
/* 2 */
#elif WCHAR_MAX > 0xff
    #define pgm_read_wchar(addr) pgm_read_word(addr)
/* ? */
#else
    #error "wchar_t is just 1 byte, check toolchain stddef.h"
#endif

#else

#define pgm_read_wchar(addr) (*addr)

#endif /* WCHAR_MAX */
