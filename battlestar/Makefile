# Makefile for battlestar
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif


PROG=battlestar
SRCS=battlestar.c command1.c command2.c command3.c command4.c command5.c command6.c command7.c init.c cypher.c getcom.c parse.c room.c save.c fly.c misc.c globals.c dayfile.c nightfile.c dayobjs.c nightobjs.c words.c
MAN=battlestar.6
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2
LDFLAGS=-lcurses
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean
