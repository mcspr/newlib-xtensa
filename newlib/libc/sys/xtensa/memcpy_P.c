/*
 memcpy_P.c - string function that supports PROGMEM

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

#include <stdint.h>
#include <stddef.h>
#include <sys/string.h>

void *
memcpy_P(void* dest, const void* src, size_t count)
{
    const uint8_t* read = (const uint8_t*)(src);
    uint8_t* write = (uint8_t*)(dest);

    // Optimize for the case when dest and src start at 4-byte alignment
    // In this case we can copy ~8x faster by simply reading and writing
    // 32-bit values until there's less than a whole word left to write
    if ( 0 == (((uint32_t)dest|(uint32_t)src) & 0x3) ) {
        const uint32_t* readW = (const uint32_t*)(src);
        uint32_t* writeW = (uint32_t*)(dest);
        while (count >= 4) {
            *writeW++ = *readW++;
            count -= 4;
        }
        // Let default byte-by-byte finish the work
        write = (uint8_t *) writeW;
        read = (const uint8_t*) readW;
    }

    while (count)
    {
        *write++ = pgm_read_byte(read++);
        count--;
    }

    return dest;
}
