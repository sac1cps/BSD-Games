# GNU make compatible Makefile for ching script
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif

SCRIPT = ching.sh
MAN = ching.6
DATA_FILES = hexagrams macros
BINDIR ?= /usr/local/bin
DATADIR ?= /usr/local/share/games
MANDIR ?= /usr/local/share/man/man6

.PHONY: all clean install

all:
	@:

install:
	install -d $(BINDIR)
	install -d $(DATADIR)
	install -d $(MANDIR)
	install -m 755 $(SCRIPT) $(BINDIR)/ching
	for f in $(DATA_FILES); do \
		install -m 644 $$f $(DATADIR); \
	done
	install -m 644 $(MAN) $(MANDIR)

clean:
	@: