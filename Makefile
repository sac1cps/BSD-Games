#	@(#)Makefile	8.2 (Berkeley) 3/31/94
# $FreeBSD: src/games/Makefile,v 1.16 1999/08/27 23:28:45 peter Exp $
# $DragonFly: src/games/Makefile,v 1.3 2008/09/02 21:50:17 dillon Exp $

# XXX missing: chess ching monop [copyright]
SUBDIR= adventure \
	arithmetic \
	atc \
	backgammon \
	battlestar \
	bcd \
	bs \
	caesar \
	canfield \
	cribbage \
	dab \
	factor \
	fish \
	grdc \
	gomoku \
	hack \
	hangman \
	hunt \
	larn \
	mille \
	number \
	phantasia \
	pig \
	pom \
	ppt \
	primes \
	quiz \
	rain \
	random \
	robots \
	rogue \
	sail \
	snake \
	trek \
	wargames \
	worm \
	worms \
	wtf \
	wump

all:
	@for dir in $(SUBDIR); do \
		echo "Building $$dir..."; \
		(cd $$dir && make); \
	done

install:
	@for dir in $(SUBDIR); do \
		echo "Installing $$dir..."; \
		(cd $$dir && make install); \
	done

clean:
	@for dir in $(SUBDIR); do \
		echo "Cleaning $$dir..."; \
		(cd $$dir && make clean); \
	done

.PHONY: all install clean