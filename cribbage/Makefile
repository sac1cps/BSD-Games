# Makefile for cribbage
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif


PROG=cribbage
SRCS=extern.c crib.c cards.c instr.c io.c score.c support.c
MAN=cribbage.6
OBJS=$(SRCS:.c=.o)
FILES=cribbage.n

CFLAGS+=-O2
LDFLAGS=-lcurses
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6
SHAREDIR?=/usr/local/share
FILESDIR?=$(SHAREDIR)/games

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install -d $(FILESDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)
	install -m 644 $(FILES) $(FILESDIR)/cribbage.instr

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean
