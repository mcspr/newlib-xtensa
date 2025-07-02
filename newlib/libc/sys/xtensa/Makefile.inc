AM_CPPFLAGS_%C% = -I$(srcdir)/libc/machine/xtensa

libc_a_SOURCES += \
	%D%/clibrary_init.c \
	%D%/creat.c \
	%D%/isattyr.c \
	%D%/lock.c \
	%D%/pgmspace/memccpy_P.c \
	%D%/pgmspace/memchr_P.c \
	%D%/pgmspace/memcmp_P.c \
	%D%/pgmspace/memcpy_P.c \
	%D%/pgmspace/memmem_P.c \
	%D%/pgmspace/memmove_P.c \
	%D%/pgmspace/printf_P.c \
	%D%/pgmspace/snprintf_P.c \
	%D%/pgmspace/sprintf_P.c \
	%D%/pgmspace/strncasecmp_P.c \
	%D%/pgmspace/strncat_P.c \
	%D%/pgmspace/strncmp_P.c \
	%D%/pgmspace/strncpy_P.c \
	%D%/pgmspace/strnlen_P.c \
	%D%/pgmspace/strstr_P.c \
	%D%/pgmspace/vsnprintf_P.c
