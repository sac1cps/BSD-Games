# Makefile for caesar

PROG=caesar
SRCS=caesar.c
MAN=caesar.6
MLINKS=caesar.6 rot13.6
OBJS=$(SRCS:.c=.o)
SCRIPTS=rot13.sh

CFLAGS+=-O2
LDFLAGS=-lm
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
	install -m 755 $(SCRIPTS) $(BINDIR)/rot13
	ln -sf $(MANDIR)/$(MLINKS)

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean