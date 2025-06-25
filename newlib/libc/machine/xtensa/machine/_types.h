/*
 *  $Id$
 */

#ifndef _MACHINE__TYPES_H
#define _MACHINE__TYPES_H

// avoid gcc provided types, preserve signatures & printf formatting
// ref. 08a150b17c55de2c038d24697d1d2b73f3d0612f
#undef __INT16_TYPE__
#define __INT16_TYPE__ short
#undef __INT32_TYPE__
#define __INT32_TYPE__ int
#undef __INT64_TYPE__
#define __INT64_TYPE__ long long

#include <machine/_default_types.h>

#ifdef _IN_ADDR_T_DECLARED
#ifndef IN_ADDR_T_DEFINED
#define IN_ADDR_T_DEFINED 1 // For LWIP2
#endif
#endif

#endif
