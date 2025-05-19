/*
 strstr_P.c - string function that supports PROGMEM

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

#include <stddef.h>
#include <sys/string.h>

char *
strstr_P(const char* haystack, const char* needle)
{
    const char* pn = (const char*)(needle);
    if (haystack[0] == 0) {
        if (pgm_read_byte(pn)) {
	        return NULL;
        }
        return (char*) haystack;
    }

    while (*haystack) {
        size_t i = 0;
        while (true) {
            char n = pgm_read_byte(pn + i);
            if (n == 0) {
                return (char *) haystack;
            }
            if (n != haystack[i]) {
                break;
            }
            ++i;
        }
        ++haystack;
    }
    return NULL;
}
