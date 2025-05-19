#pragma once

#include <xtensa/config/core-isa.h>
#include <stdint.h>
#include <stdbool.h>

static inline bool __pgm_expected(const void *p)
{
    return ((uintptr_t)p & (uintptr_t)XCHAL_INSTRAM0_VADDR) > 0;
}

#define __pgm_likely(p)\
    __builtin_expect (__pgm_expected (p), 1)

#define __pgm_unlikely(p)\
    __builtin_expect (__pgm_expected (p), 0)
