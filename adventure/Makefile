# Makefile for adventure
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif


PROG=adventure
SRCS=main.c init.c done.c save.c subr.c vocab.c wizard.c io.c data.c crc.c
MAN=adventure.6
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2
LDFLAGS=
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

setup.nx: setup.c
	$(CC) -o setup.nx setup.c

data.c: setup.nx glorkz
	./setup.nx glorkz > data.c

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)

clean:
	rm -f $(PROG) $(OBJS) data.c setup.nx

.PHONY: all install clean