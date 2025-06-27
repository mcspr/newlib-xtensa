## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

lib_a_SOURCES = setjmp.S

## ESP8266 ROM funcs that override newlib ones
lib_a_SOURCES += strcpy.c strncpy.c
lib_a_SOURCES += bzero.S memcmp.S memcpy.S memmove.S memset.S strcmp.S strlen.S strncmp.S strstr.S

## Preserve original newlib-xtensa files as `fast_$NAME.S`
lib_a_SOURCES += fast_memcpy.S fast_memset.S fast_strcmp.S fast_strcpy.S fast_strlen.S fast_strncpy.S

lib_a_CCASFLAGS=$(AM_CCASFLAGS)
lib_a_CFLAGS=$(AM_CFLAGS)
TARGETDOC = ../../tmp.texi

doc:
	cat $(srcdir)/xtensa.tex >> $(TARGETDOC)

ACLOCAL_AMFLAGS = -I ../../.. -I ../../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
