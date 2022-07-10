#test _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

EE_BIN = main.elf
EE_OBJS = src/main.o src/thread.o src/tswitch.o
EE_LIBS = -lpatches -ldebug
EE_INCS += -I$(PS2DEV)/gsKit/include -Iinclude
EE_LDFLAGS += -L$(PS2DEV)/gsKit/lib -L$(PS2SDK)/ports/lib
EE_ASFLAGS += -msingle-float
EE_CFLAGS += -Wall -Werror-implicit-function-declaration -Wdeclaration-after-statement


all: $(EE_BIN)

clean:
	rm -f $(EE_BIN) $(EE_OBJS)

run: $(EE_BIN)
	ps2client execee host:$(EE_BIN)

sim: $(EE_BIN)
	PCSX2 --elf=$(PWD)/$(EE_BIN) --nogui

reset:
	ps2client reset

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
