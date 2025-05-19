/*
 memcmp_P.c - string function that supports PROGMEM

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

int
memcmp_P(const void* buf1, const void* buf2P, size_t size)
{
    int result = 0;
    const uint8_t* read1 = (const uint8_t*)buf1;
    const uint8_t* read2 = (const uint8_t*)buf2P;

    while (size > 0) {
        uint8_t ch2 = pgm_read_byte(read2);
        uint8_t ch1 = *read1;
        if (ch1 != ch2) {
            result = (int)(ch1)-(int)(ch2);
            break;
        }

        read1++;
        read2++;
        size--;
    }

    return result;
}
