/* sys/ctype.h - PROGMEM ctype handlers */
#ifndef _CTYPE_H_
#error "must be included via <ctype.h>"
#endif

#ifndef _SYS_CTYPE_H_
#define _SYS_CTYPE_H_

#include <sys/pgmspace.h>

#define __ctype_lookup(__c) pgm_read_byte(&(__CTYPE_PTR+sizeof(""[__c]))[(int)(__c)])
#define __ctype_lookup_l(__c,__l) pgm_read_byte(&((__locale_ctype_ptr_l(__l)+sizeof(""[__c]))[(int)(__c)]))

#endif /* _SYS_CTYPE_H_ */
