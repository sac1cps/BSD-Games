# GNU make compatible Makefile for wargames script
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
