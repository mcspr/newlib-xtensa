## avr-like functions to access data from memory that only allows 32bit aligned reads
libc_a_SOURCES += \
    %D%/memccpy_P.c \
    %D%/memchr_P.c \
    %D%/memcmp_P.c \
    %D%/memcpy_P.c \
    %D%/memmem_P.c \
    %D%/memmove_P.c \
    %D%/strncasecmp_P.c \
    %D%/strncat_P.c \
    %D%/strncmp_P.c \
    %D%/strncpy_P.c \
    %D%/strnlen_P.c \
    %D%/strstr_P.c
