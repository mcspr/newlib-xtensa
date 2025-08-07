## ESP8266 - crt0.o comes from here, not libgloss
## TODO - at least one file must be here for .deps/ aka DEPDIR to be created for CC implicit temporary files location
libc_a_SOURCES += %D%/crt0_unused.c
