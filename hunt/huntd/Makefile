# Makefile for huntd

PROG=huntd
SRCS=answer.c conf.c draw.c driver.c execute.c expl.c extern.c makemaze.c shots.c terminal.c
MAN=huntd.6
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2
LDFLAGS=
BINDIR?=/usr/local/sbin
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