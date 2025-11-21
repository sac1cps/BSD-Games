# Makefile for gomoku

PROG=gomoku
SRCS=bdinit.c bdisp.c main.c makemove.c pickmove.c stoc.c
MAN=gomoku.6
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