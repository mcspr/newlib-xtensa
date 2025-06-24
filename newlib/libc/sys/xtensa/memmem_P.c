/*
 memmem_P.c - string function that supports PROGMEM

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

#include <sys/string.h>
#include <sys/pgmspace.h>

void*
memmem_P(const void* buf, size_t bufSize, const void* findP, size_t findPSize)
{
    const uint8_t* read = (const uint8_t*)buf;
    const uint8_t* find = (uint8_t*)findP;
    uint8_t first = pgm_read_byte(find++);

    if (!findPSize)
        return (void *)buf;

    findPSize--;

    while (bufSize > 0) {
        if (*read == first) {
            size_t findSize = findPSize;
            const uint8_t* tag = read + 1;
            size_t tagBufSize = bufSize - 1;
            const uint8_t* findTag = find;

            while (tagBufSize > 0 && findSize > 0) {
                uint8_t ch = pgm_read_byte(findTag++);
                if (ch != *tag) {
                    bufSize--;
                    read++;
                    break;
                }
                findSize--;
                tagBufSize--;
                tag++;
            }
            if (findSize == 0) {
                return (void*)read;
            }
        }
        else {
            bufSize--;
            read++;
        }
    }
    return NULL;
}
