# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2005, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

IOP_BIN = gore.irx
IOP_OBJS = src/gore.o imports.o
IOP_LIBS =

IOP_CFLAGS += -Wall -fno-common -Werror-implicit-function-declaration -std=c99

all: $(IOP_BIN)
clean:
	rm -f $(IOP_BIN) $(IOP_OBJS)

run: $(IOP_BIN)
	ps2client execiop host:$(IOP_BIN)

sim: $(IOP_BIN)
	PCSX2 --elf="hello.elf"

#PCSX2 --irx=$(IOP_BIN)

reset:
	ps2client reset

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.iopglobal
