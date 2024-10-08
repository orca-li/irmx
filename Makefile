CC := gcc
# CF := -Wall -Werror -Wextra
CF :=

OUTDIR := dbg
OUTFILE := $(OUTDIR)/irmx

SRCDIR := src
PCKSRCDIR := pck/src
# LIBSRCDIR := lib/libbwp/src
LSRCD2 := lib/mprimf/src

SOURCES += $(wildcard $(SRCDIR)/*.c)
SOURCES += $(wildcard $(PCKSRCDIR)/*.c)
SOURCES += $(wildcard $(LIBSRCDIR)/*.c)
SOURCES += $(wildcard $(LSRCD2)/*.c)

INCDIR := inc
INCLUDES += -I"inc"
INCLUDES += -I"lib/libbwp/inc"
INCLUDES += -I"lib/mprimf/inc"
INCLUDES += -I"pck/inc"

all:
	@mkdir -p $(OUTDIR)
	$(CC) $(CF) $(INCLUDES) $(SOURCES) -o $(OUTFILE)

clean:
	rm -rf dbg/