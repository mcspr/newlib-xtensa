AM_CPPFLAGS_%C% = -I$(srcdir)/libc/machine/xtensa

libc_a_SOURCES += \
	%D%/lock.c \
	%D%/printf_P.c \
	%D%/snprintf_P.c \
	%D%/sprintf_P.c \
	%D%/vsnprintf_P.c \
	%D%/memccpy_P.c \
	%D%/memchr_P.c \
	%D%/memcmp_P.c \
	%D%/memcpy_P.c \
	%D%/memmem_P.c \
	%D%/strncasecmp_P.c \
	%D%/strncat_P.c \
	%D%/strncmp_P.c \
	%D%/strncpy_P.c \
	%D%/strnlen_P.c \
	%D%/strnstr_P.c \
	%D%/strstr_P.c
