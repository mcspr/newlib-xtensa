%C%_CPPFLAGS = -D_LIBGLOSS -I$(srcdir)/%D%/include

multilibtool_DATA += \
	%D%/default.specs \
	%D%/crt0.o

if HAVE_XTENSA_BOARDS
multilibtool_DATA += \
	%D%/nano.specs \
	%D%/sim.elf.specs \
	%D%/board.elf.specs
if HAVE_XTENSA_QEMU
multilibtool_DATA += \
	%D%/sys.qemu.specs
endif
if HAVE_XTENSA_OPENOCD
multilibtool_DATA += \
	%D%/sys.openocd.specs
endif
endif

libobjs_a_SOURCES += \
	%D%/crt0.S

if HAVE_XTENSA_BOARDS
libobjs_a_SOURCES += \
	%D%/crt1-sim.S
	%D%/crt1-boards.S
endif

multilibtool_LIBRARIES += %D%/libgloss.a

if HAVE_XTENSA_BOARD_ESP
if HAVE_XTENSA_BOARDS
multilibtool_DATA += \
	%D%/app.elf.ld \
	%D%/crt1-sim.o \
	%D%/crt1-boards.o
endif

%C%_libgloss_a_SOURCES = \
	%D%/clibrary_init.c \
	%D%/sleep.S \
	%D%/syscalls.c

if HAVE_XTENSA_WINDOWED
%C%_libgloss_a_SOURCES += \
	%D%/window-vectors.S
endif

%C%_libgloss_a_CPPFLAGS = $(AM_CPPFLAGS) $(%C%_CPPFLAGS)

if HAVE_XTENSA_QEMU
multilibtool_LIBRARIES += %D%/libsys_qemu.a
%C%_libsys_qemu_a_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	$(%C%_CPPFLAGS) \
	-DQEMU_SEMIHOSTING
%C%_libsys_qemu_a_SOURCES = \
	%D%/sim-vectors.S \
	%D%/sim-call.S \
	%D%/syscalls.c
endif

if HAVE_XTENSA_OPENOCD
multilibtool_LIBRARIES += %D%/libsys_openocd.a
%C%_libsys_openocd_a_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	$(%C%_CPPFLAGS) \
	-DOPENOCD_SEMIHOSTING
%C%_libsys_openocd_a_SOURCES = \
	%D%/syscalls.c
endif

if HAVE_XTENSA_BOARD_ESP8266
multilibtool_DATA += %D%/boards/esp8266/memory.elf.ld
%C%_libgloss_a_SOURCES += %D%/boards/esp8266/board.c
%C%_libgloss_a_CPPFLAGS += -I$(srcdir)/%D%/boards/esp8266/include
endif

if HAVE_XTENSA_BOARD_ESP32
multilibtool_DATA += %D%/boards/esp32/memory.elf.ld
%C%_libgloss_a_SOURCES += %D%/boards/esp32/board.c
%C%_libgloss_a_CPPFLAGS += -I$(srcdir)/%D%/boards/esp32/include
if HAVE_XTENSA_QEMU
%C%_libsys_qemu_a_CPPFLAGS += -I$(srcdir)/%D%/boards/esp32/include
endif
if HAVE_XTENSA_OPENOCD
%C%_libsys_openocd_a_CPPFLAGS += -I$(srcdir)/%D%/boards/esp32/include
endif
endif

if HAVE_XTENSA_BOARD_ESP32S3
multilibtool_DATA += %D%/boards/esp32s3/memory.elf.ld
%C%_libgloss_a_SOURCES += %D%/boards/esp32s3/board.c
%C%_libgloss_a_CPPFLAGS += -I$(srcdir)/%D%/boards/esp32s3/include
if HAVE_XTENSA_QEMU
%C%_libsys_qemu_a_CPPFLAGS += -I$(srcdir)/%D%/boards/esp32s3/include
endif
if HAVE_XTENSA_OPENOCD
%C%_libsys_openocd_a_CPPFLAGS += -I$(srcdir)/%D%/boards/esp32s3/include
endif
endif
endif
