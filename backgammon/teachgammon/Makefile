# GNU make compatible Makefile for teachgammon
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif

VPATH = ../common_source

PROG = teachgammon
SRCS = allow.c board.c check.c data.c fancy.c init.c odds.c one.c \
	save.c subs.c table.c teach.c ttext1.c ttext2.c tutor.c
OBJS = $(SRCS:.c=.o)
CFLAGS += -O2 -DTEACHGAMMON_TEXT -I../common_source
LDLIBS += -lcurses
BINDIR ?= /usr/local/bin

.PHONY: all clean install

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

install: $(PROG)
	install -d $(BINDIR)
	install $(PROG) $(BINDIR)

clean:
	rm -f $(PROG) $(OBJS)
