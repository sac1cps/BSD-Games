# GNU make compatible Makefile for castching
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif

PROG = castching
SRCS = castching.c
OBJS = $(SRCS:.c=.o)
CFLAGS += -O2
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