AM_CPPFLAGS_%C% = -I$(srcdir)/libc/machine/xtensa

libc_a_SOURCES += \
	%D%/clibrary_init.c \
	%D%/creat.c \
	%D%/isatty.c \
	%D%/lock.c \
	%D%/stdio_pgmspace.c \
	%D%/string_pgmspace.c
