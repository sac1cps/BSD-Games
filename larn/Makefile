# Makefile for larn

PROG=larn
SRCS=main.c object.c create.c tok.c display.c global.c data.c io.c monster.c store.c diag.c help.c config.c nap.c bill.c scores.c signal.c moreobj.c movem.c regen.c fortune.c savelev.c
MAN=larn.6
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2 -DVER=12 -DSUBVER=0 -DNONAP -DUIDSCORE
LDFLAGS=-ltermcap
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6
SHAREDIR?=/usr/local/share
FILESDIR?=$(SHAREDIR)/games/larn

FILES=larnmaze larnopts larn.help

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install -d $(FILESDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)
	for file in $(FILES); do \
		install -m 644 datfiles/$$file $(FILESDIR); \
	done

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean