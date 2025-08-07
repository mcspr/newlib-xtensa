/* Utility functions for *_P */

#ifndef _XTENSA__PGMSPACE_H_
#define _XTENSA__PGMSPACE_H_

#include <xtensa/config/core-isa.h>
#include <stdint.h>
#include <stdbool.h>

/* XCHAL_INSTROM0_VADDR (0x40200000) for flash contents
 * XCHAL_INSTRAM0_VADDR (0x40000000) for instram, aka 1 << 30 */
static inline bool __attribute__((always_inline)) __pgm_expected(const void *p)
{
    return ((uintptr_t)p & (uintptr_t)((1 << 31) | (1 << 30))) > 0;
}

#define __pgm_likely(p)\
    __builtin_expect (__pgm_expected (p), 1)

#define __pgm_unlikely(p)\
    __builtin_expect (__pgm_expected (p), 0)

#endif
