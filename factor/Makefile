# Makefile for factor
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif


PROG=factor
SRCS=factor.c pr_tbl.c
MAN=factor.6
MLINKS=factor.6 primes.6
OBJS=factor.o pr_tbl.o

CFLAGS+=-O2 -I../primes -I/opt/homebrew/opt/openssl/include
LDFLAGS=-L/opt/homebrew/opt/openssl/lib -lcrypto
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

pr_tbl.o: ../primes/pr_tbl.c
	$(CC) $(CFLAGS) -c ../primes/pr_tbl.c -o pr_tbl.o

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)
	ln -sf $(MANDIR)/$(MLINKS)

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean