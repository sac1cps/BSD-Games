# GNU make compatible Makefile for wargames script
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif

SCRIPT = wargames.sh
MAN = wargames.6
BINDIR ?= /usr/local/bin
MANDIR ?= /usr/local/man/man6

.PHONY: all clean install

all:
	@:

install:
	install -d $(BINDIR)
	install -d $(MANDIR)
	install -m 755 $(SCRIPT) $(BINDIR)/wargames
	install -m 644 $(MAN) $(MANDIR)

clean:
	@: