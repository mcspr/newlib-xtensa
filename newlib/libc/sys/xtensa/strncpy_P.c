/*
 strncpy_P.c - string function that supports PROGMEM

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

// TODO - Optimize these routines to use 32-bit accesses whenever possible

#define __need_size_t
#include <stddef.h>

#include <stdbool.h>
#include <stdint.h>

#include <sys/string.h>
#include <sys/pgmspace.h>

char *
strncpy_P(char* __restrict dest, const char* __restrict src, size_t size)
{
    bool size_known = (size != SIZE_IRRELEVANT);
    const char* read = src;
    char* write = dest;
    char ch = '.';

    // Optimize for the case when the src starts at 4-byte alignment
    // In this case we can copy ~4x faster by simply reading and writing
    // 32-bit values until there's less than a whole word left to write
    if (!((((uint32_t)src)|(uint32_t)dest) & 0x3)) {
        while (size >= 4) {
            uint32_t p = *(uint32_t*)read;
            // Bit of magic to check if any bytes are 0 in the word, adapted from:
            // https://jameshfisher.com/2017/01/24/bitwise-check-for-zero-byte.html
            int hasZero = (p - 0x01010101) & ~p & 0x80808080;
            if (hasZero) {
                // Don't handle the partial word case here, use standard flow
                break;
            } else {
                *(uint32_t *)write = p;
                read += 4;
                write += 4;
                size -= 4;
            }
        }
    }

    while (size > 0 && ch != '\0')
    {
        ch = pgm_read_byte(read++);
        *write++ = ch;
        size--;
    }
    if (size_known)
    {
        while (size > 0)
        {
            *write++ = 0;
            size--;
        }
    }

    return dest;
}
