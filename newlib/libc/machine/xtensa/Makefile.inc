libc_a_SOURCES += \
	%D%/memccpy.c %D%/memchr.c %D%/memcmp.c %D%/memcpy.c \
	%D%/memmove.c %D%/strcasecmp.c %D%/strcat.c %D%/strcmp.c \
	%D%/strcpy.c %D%/strlen.c %D%/strncasecmp.c %D%/strncat.c \
	%D%/strncmp.c %D%/strncpy.c %D%/strnlen.c %D%/strstr.c \
	%D%/fast_strcpy.S %D%/fast_strncpy.S %D%/setjmp.S

libc_a_SOURCES += \
	%D%/atexit.c \
	%D%/bzero.S \
	%D%/time.S

if XTENSA_ESP32_PSRAM_CACHE_FIX
libc_a_CPPFLAGS_%C% = \
	-DXTENSA_ESP32_PSRAM_CACHE_FIX
endif
