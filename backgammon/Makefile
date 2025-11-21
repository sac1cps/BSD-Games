# Simplified aggregator Makefile for GNU make
SUBDIRS = backgammon teachgammon

.PHONY: all clean install

all:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

install:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir install; \
	done
