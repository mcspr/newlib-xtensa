/*
 * asctime.c
 * Original Author:	G. Haley
 *
 * Converts the broken down time in the structure pointed to by tim_p into a
 * string of the form
 *
 * Wed Jun 15 11:38:07 1988\n\0
 *
 * Returns a pointer to the string.
 */

/*
FUNCTION
<<asctime>>---format time as string

INDEX
	asctime
INDEX
	_asctime_r

SYNOPSIS
	#include <time.h>
	char *asctime(const struct tm *<[clock]>);
	char *_asctime_r(const struct tm *<[clock]>, char *<[buf]>);

DESCRIPTION
Format the time value at <[clock]> into a string of the form
. Wed Jun 15 11:38:07 1988\n\0
The string is generated in a static buffer; each call to <<asctime>>
overwrites the string generated by previous calls.

RETURNS
A pointer to the string containing a formatted timestamp.

PORTABILITY
ANSI C requires <<asctime>>.

<<asctime>> requires no supporting OS subroutines.
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <_ansi.h>
#include <reent.h>

#ifndef _REENT_ONLY

char *
asctime (const struct tm *tim_p)
{
  struct _reent *reent = _REENT;

  _REENT_CHECK_ASCTIME_BUF(reent);
  return asctime_r (tim_p, _REENT_ASCTIME_BUF(reent));
}

#endif
