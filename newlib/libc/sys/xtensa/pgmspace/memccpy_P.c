/*
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

#include <stdint.h>

#include <string.h>
#include <sys/pgmspace.h>

void* memccpy_P(void* dest, const void* src, int c, size_t count)
{
    uint8_t* read = (uint8_t*)src;
    uint8_t* write = (uint8_t*)dest;
    void* result = NULL;

    while (count > 0) {
        uint8_t ch = pgm_read_byte(read++);
        *write++ = ch;
        count--;
        if (c == ch) {
            return write; // the value after the found c
        }
    }

    return result;
}
