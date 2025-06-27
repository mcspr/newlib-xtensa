## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = cygnus

INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

noinst_LIBRARIES = lib.a

lib_a_SOURCES = atexit.c creat.c isatty.c clibrary_init.c lock.c

## avr-like functions to access data from memory that only allows 32bit aligned reads
lib_a_SOURCES += \
  pgmspace/memccpy_P.c \
  pgmspace/memchr_P.c \
  pgmspace/memcmp_P.c \
  pgmspace/memcpy_P.c \
  pgmspace/memmem_P.c \
  pgmspace/memmove_P.c \
  pgmspace/strncasecmp_P.c \
  pgmspace/strncat_P.c \
  pgmspace/strncmp_P.c \
  pgmspace/strncpy_P.c \
  pgmspace/strnlen_P.c \
  pgmspace/strstr_P.c

## backwards compatible *printf, effectively call functions w/o _P suffix
lib_a_SOURCES += \
  pgmspace/printf_P.c \
  pgmspace/snprintf_P.c \
  pgmspace/sprintf_P.c \
  pgmspace/vsnprintf_P.c

crt0.o: crt0.S
all: crt0.o

ACLOCAL_AMFLAGS = -I ../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host
