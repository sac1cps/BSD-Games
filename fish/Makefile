# Makefile for fish

PROG=fish
SRCS=fish.c
MAN=fish.6
OBJS=$(SRCS:.c=.o)
FILES=fish.instr

CFLAGS+=-O2
LDFLAGS=
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
	install -m 644 $(FILES) $(FILESDIR)

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean