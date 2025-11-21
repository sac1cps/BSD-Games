# Makefile for hack
ROOTDIR ?= $(shell d="$(CURDIR)"; \
	while [ ! -f "$$d/compat.h" -a "$$d" != "/" ]; do \
		d=$$(dirname "$$d"); \
	done; \
	echo $$d)
ifneq ($(wildcard $(ROOTDIR)/compat.h),)
CFLAGS += -include $(ROOTDIR)/compat.h
CFLAGS += -fcommon
endif

PROG=hack
SRCS=alloc.c hack.Decl.c hack.apply.c hack.bones.c hack.c hack.cmd.c hack.do.c hack.do_name.c hack.do_wear.c hack.dog.c hack.eat.c hack.end.c hack.engrave.c hack.fight.c hack.invent.c hack.ioctl.c hack.lev.c hack.main.c hack.makemon.c hack.mhitu.c hack.mklev.c hack.mkmaze.c hack.mkobj.c hack.mkshop.c hack.mon.c hack.monst.c hack.o_init.c hack.objnam.c hack.options.c hack.pager.c hack.potion.c hack.pri.c hack.read.c hack.rip.c hack.rumors.c hack.save.c hack.search.c hack.shk.c hack.shknam.c hack.steal.c hack.termcap.c hack.timeout.c hack.topl.c hack.track.c hack.trap.c hack.tty.c hack.u_init.c hack.unix.c hack.vault.c hack.version.c hack.wield.c hack.wizard.c hack.worm.c hack.worn.c hack.zap.c rnd.c
MAN=hack.6
OBJS=$(SRCS:.c=.o)

CFLAGS+=-O2 -I.
LDFLAGS=-lcurses
BINDIR?=/usr/local/bin
MANDIR?=/usr/local/man/man6
VARDIR?=/var/games
FILESDIR?=$(VARDIR)/hackdir

FILES=rumors help hh data

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

makedefs.nx: makedefs.c
	$(CC) -o makedefs.nx makedefs.c

hack.onames.h: makedefs.nx def.objects.h
	./makedefs.nx def.objects.h > hack.onames.h

$(OBJS): hack.onames.h

install: $(PROG)
	install -d $(BINDIR)
	install -d $(MANDIR)
	install -d $(FILESDIR)
	install $(PROG) $(BINDIR)
	install -m 644 $(MAN) $(MANDIR)
	for file in $(FILES); do \
		install -m 644 $$file $(FILESDIR); \
	done

clean:
	rm -f $(PROG) $(OBJS) hack.onames.h makedefs.nx

.PHONY: all install clean
