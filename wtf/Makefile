# GNU make compatible Makefile for wtf script
SCRIPT = wtf
DATA_FILES = acronyms acronyms.comp
MAN = wtf.6
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
	install -m 755 $(SCRIPT) $(BINDIR)
	for f in $(DATA_FILES); do \
		install -m 644 $$f $(DATADIR); \
	done
	install -m 644 $(MAN) $(MANDIR)

clean:
	@:
