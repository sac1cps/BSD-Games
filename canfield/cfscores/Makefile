# Makefile for cfscores

PROG=cfscores
SRCS=cfscores.c
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2 -I../canfield
LDFLAGS=
BINDIR?=/usr/local/bin

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

install: $(PROG)
	install -d $(BINDIR)
	install $(PROG) $(BINDIR)

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean