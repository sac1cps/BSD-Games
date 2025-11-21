# GNU make compatible Makefile for snscore
PROG = snscore
SRCS = snscore.c
OBJS = $(SRCS:.c=.o)
CFLAGS += -O2 -I../snake
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
