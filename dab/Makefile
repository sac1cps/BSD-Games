# Makefile for dab
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif


PROG=dab
SRCS=algor.cc board.cc main.cc human.cc box.cc player.cc gamescreen.cc ttyscrn.cc random.cc
MAN=dab.6
OBJS=$(SRCS:.cc=.o)

CXX=g++
CXXFLAGS+=-O2 -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1
LDFLAGS=-lcurses -lm
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(OBJS) $(LDFLAGS)

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)

clean:
	rm -f $(PROG) $(OBJS)

.PHONY: all install clean
