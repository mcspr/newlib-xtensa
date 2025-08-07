libc_a_SOURCES += \
	%D%/setjmp.S \
	%D%/atexit.c \
	%D%/bzero.S \
	%D%/time.c

## ESP8266 ROM funcs that override newlib ones
libc_a_SOURCES += \
	%D%/memcmp.S \
	%D%/memcpy.S \
	%D%/memmove.S \
	%D%/memset.S \
	%D%/strcmp.S \
	%D%/strlen.S \
	%D%/strncmp.S \
	%D%/strstr.S

## ESP8266 ROM overrides that jump to either fast_... or ..._P
libc_a_SOURCES += \
	%D%/strcpy.c \
	%D%/strncpy.c

## Preserve original newlib-xtensa files as `fast_$NAME.S`
libc_a_SOURCES += \
	%D%/fast_memcpy.S \
	%D%/fast_memset.S \
	%D%/fast_strcmp.S \
	%D%/fast_strcpy.S \
	%D%/fast_strlen.S \
	%D%/fast_strncpy.S
