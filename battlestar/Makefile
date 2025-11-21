# Makefile for battlestar

PROG=battlestar
SRCS=battlestar.c command1.c command2.c command3.c command4.c command5.c command6.c command7.c init.c cypher.c getcom.c parse.c room.c save.c fly.c misc.c globals.c dayfile.c nightfile.c dayobjs.c nightobjs.c words.c
MAN=battlestar.6
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2
LDFLAGS=-lcurses -ltermcap
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