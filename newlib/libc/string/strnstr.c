/*
FUNCTION
	<<strnstr>>---find string segment

INDEX
	strnstr

SYNOPSIS
	#include <string.h>
	size_t strnstr(const char *<[s1]>, const char *<[s2]>, size_t <[n]>);

DESCRIPTION
	Locates the first occurrence in the string pointed to by <[s1]> of
	the sequence of limited to the <[n]> characters in the string
        pointed to by <[s2]>

RETURNS
	Returns a pointer to the located string segment, or a null
	pointer if the string <[s2]> is not found. If <[s2]> points to
	a string with zero length, <[s1]> is returned.


PORTABILITY
<<strnstr>> is a BSD extension.

<<strnstr>> requires no supporting OS subroutines.

QUICKREF
	strnstr pure

*/

#define	_GNU_SOURCE
#include <string.h>

/*
 * Find the first occurrence of find in s, where the search is limited to the
 * first slen characters of s.
 */
char *
newlib_strnstr(const char *haystack, const char *needle, size_t haystack_len)
{
  extern size_t newlib_strnlen(const char*, size_t);
  extern void *newlib_memmem(const void*, size_t, const void*, size_t);
  extern void *newlib_memchr(const void*, int, size_t);

  size_t needle_len = newlib_strnlen(needle, haystack_len);

  if (needle_len < haystack_len || !needle[needle_len]) {
    char *x = newlib_memmem(haystack, haystack_len, needle, needle_len);
    if (x && !newlib_memchr(haystack, 0, x - haystack))
      return x;
  }
  return NULL;
}
