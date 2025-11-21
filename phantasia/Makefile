# GNU make compatible Makefile for phantasia
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif

PROG = phantasia
SRCS = main.c fight.c io.c interplayer.c gamesupport.c misc.c phantglobs.c
OBJS = $(SRCS:.c=.o)
MAN = phantasia.6
CFLAGS += -O2
LDLIBS += -lm -lcurses
BINDIR ?= /usr/local/bin
MANDIR ?= /usr/local/man/man6

.PHONY: all clean install

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)

clean:
	rm -f $(PROG) $(OBJS)
