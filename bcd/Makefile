# Makefile for bcd

PROG=bcd
SRCS=bcd.c
MAN=bcd.6
MLINKS=bcd.6 ppt.6
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2
LDFLAGS=
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
	ln -sf $(MANDIR)/$(MLINKS)

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean