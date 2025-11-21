# GNU make compatible Makefile for teachgammon
VPATH = ../common_source

PROG = teachgammon
SRCS = allow.c board.c check.c data.c fancy.c init.c odds.c one.c \
	save.c subs.c table.c teach.c ttext1.c ttext2.c tutor.c
OBJS = $(SRCS:.c=.o)
CFLAGS += -O2 -DTEACHGAMMON_TEXT -I../common_source
LDLIBS += -ltermcap
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
