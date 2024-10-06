CC := gcc
CF := -Wall -Werror -Wextra

OUTDIR := dbg
OUTFILE := $(OUTDIR)/irmx

SRCDIR := src
SOURCES += $(wildcard $(SRCDIR)/*.c)

INCDIR := inc
INCLUDES += -I"inc"

LIBSRCDIR := lib/libbwp/src
LIBSRC += $(wildcard $(LIBSRCDIR)/*.c)

LIBINC += -I"lib/libbwp/inc"


ALLSRC += $(wildcard $(SOURCES))
ALLSRC += $(wildcard $(LIBSRC))

ALLINC += $(LIBINC)
ALLINC += $(INCLUDES)

all:
	@mkdir -p $(OUTDIR)
	$(CC) $(CF) $(ALLINC) $(ALLSRC) -o $(OUTFILE)

clean:
	rm -rf dbg/