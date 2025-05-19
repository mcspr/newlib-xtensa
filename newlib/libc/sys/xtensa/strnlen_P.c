/*
 strnlen_P.c - string function that supports PROGMEM

 Modified from original source by Earle F. Philhower, III
 Original authorship:
 Copyright (c) 2015 Michael C. Miller.  All right reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stddef.h>
#include <stdint.h>
#include <sys/string.h>

size_t
strnlen_P(const char* s, size_t size)
{
    const char *cp = s;
    const uint32_t *pmem;
    char c = 0;

    // Take care of any misaligned starting data
    while ( (size > 0) && ((uint32_t)cp & 0x3) ) {
        c = pgm_read_byte(cp);
        if (!c) goto done;
        size--;
        cp++;
    }

    // We didn't find the end in the initial misaligned bits
    // Now try it 32-bits at a time while possible
    pmem = (const uint32_t*)cp;
    while (size > 3) {
      uint32_t w = *pmem;
      if (0 == (w & 0xff)) {
        cp = (const char *)pmem;
        goto done;
      }
      w = w >> 8;
      if (0 == (w & 0xff)) {
        cp = (const char *)pmem + 1;
        goto done;
      }
      w = w >> 8;
      if (0 == (w & 0xff)) {
        cp = (const char *)pmem + 2;
        goto done;
      }
      w = w >> 8;
      if (0 == (w & 0xff)) {
        cp = (const char *)pmem + 3;
        goto done;
      }
      pmem++;
      size -= 4;
    }

    // Take care of any straggling bytes
    cp = (const char *)pmem;
    while ( size > 0 ) {
        c = pgm_read_byte(cp);
        if (!c) goto done;
        size--;
        cp++;
    }

done:
    return (size_t) (cp - s);
}
