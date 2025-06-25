libc_a_SOURCES += \
	%D%/strcpy.c %D%/strncpy.c %D%/setjmp.S \
	%D%/bzero.S %D%/memcmp.S %D%/memcpy.S %D%/memmove.S %D%/memset.S %D%/strcmp.S %D%/strlen.S %D%/strncmp.S %D%/strstr.S \
	%D%/fast_memcpy.S %D%/fast_memset.S %D%/fast_strcmp.S %D%/fast_strcpy.S \
	%D%/fast_strlen.S %D%/fast_strncpy.S

if XTENSA_ESP32_PSRAM_CACHE_FIX
libc_a_CPPFLAGS_%C% = \
	-DXTENSA_ESP32_PSRAM_CACHE_FIX
endif
