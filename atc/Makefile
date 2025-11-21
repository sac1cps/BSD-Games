# Makefile for atc
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif


PROG=atc
SRCS=extern.c graphics.c input.c list.c log.c main.c tunable.c update.c
MAN=atc.6
OBJS=$(SRCS:.c=.o) grammar.o lex.o

CFLAGS+=-O2 -I.
LDFLAGS=-lfl -lm -lcurses
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6
SHAREDIR?=/usr/local/share
FILESDIR?=$(SHAREDIR)/games/atc

FILES=Game_List Killer crossover default easy game_2

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

lex.c: lex.l
	lex -o lex.c lex.l

lex.o: lex.c y.tab.h
	$(CC) $(CFLAGS) -c lex.c

y.tab.h: grammar.y
	bison -d -o y.tab.c grammar.y

grammar.c: grammar.y
	bison -o grammar.c grammar.y

grammar.o: grammar.c
	$(CC) $(CFLAGS) -c grammar.c

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install -d $(FILESDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)
	for file in $(FILES); do \
		install -m 644 games/$$file $(FILESDIR); \
	done

clean:
	rm -f $(PROG) $(OBJS) lex.c grammar.c y.tab.h

.PHONY: all install clean
