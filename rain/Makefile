# GNU make compatible Makefile for rain
PROG = rain
SRCS = rain.c
OBJS = $(SRCS:.c=.o)
MAN = rain.6
CFLAGS += -O2
LDLIBS += -lcurses -ltermcap
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
