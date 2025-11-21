# GNU make compatible Makefile for wump
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif

PROG = wump
SRCS = wump.c
OBJS = $(SRCS:.c=.o)
MAN = wump.6
DATA_FILES = wump.info
CFLAGS += -O2
BINDIR ?= /usr/local/bin
MANDIR ?= /usr/local/man/man6
DATADIR ?= /usr/local/share/games

.PHONY: all clean install

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install -d $(DATADIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)
	install -m 644 $(DATA_FILES) $(DATADIR)

clean:
	rm -f $(PROG) $(OBJS)