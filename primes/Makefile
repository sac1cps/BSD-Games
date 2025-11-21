# GNU make compatible Makefile for primes
PROG = primes
SRCS = pattern.c pr_tbl.c primes.c
OBJS = $(SRCS:.c=.o)
CFLAGS += -O2
LDLIBS += -lm
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
