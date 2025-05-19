/*
 strncasecmp_P.c - string function that supports PROGMEM

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

#include <ctype.h>
#include <stddef.h>
#include <sys/string.h>

int
strncasecmp_P(const char* s1, const char* s2, size_t size)
{
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    int result = 0;

    while (size > 0)
    {
        const int c1 = tolower(*p1++);
        const int c2 = tolower(pgm_read_byte(p2++));
        result = c1 - c2;
        if (result != 0 || c2 == '\0')
        {
            break;
        }

        size--;
    }

    return result;
}

