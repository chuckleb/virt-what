# Makefile for virt-what
#
# Copyright (C) 2008-2009 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

PACKAGE	= virt-what
VERSION	= 1.0

prefix	= /usr/local
bindir	= $(prefix)/bin
mandir	= $(prefix)/share/man

all:	virt-what.1 virt-what.txt virt-what

virt-what: virt-what.sh
	sed -e 's/@VERSION@/$(VERSION)/g' < $< > $@
	chmod 0755 $@

virt-what.1: virt-what.pod
	pod2man -c "Virtualization Support" --release "$(PACKAGE)-$(VERSION)" \
	  $< > $@

virt-what.txt: virt-what.pod
	pod2text $< > $@

clean:
	rm -f virt-what virt-what.1 virt-what.txt
	rm -f *~

# Install.

install:
	mkdir -p $(DESTDIR)$(bindir)
	mkdir -p $(DESTDIR)$(mandir)/man1
	install -m 0755 virt-what $(DESTDIR)$(bindir)/
	install -m 0644 virt-what.1 $(DESTDIR)$(mandir)/man1/

# Distribution.

dist:
	$(MAKE) check-manifest
	rm -rf $(PACKAGE)-$(VERSION)
	mkdir $(PACKAGE)-$(VERSION)
	tar -cf - -T MANIFEST | tar -C $(PACKAGE)-$(VERSION) -xf -
	tar zcf $(PACKAGE)-$(VERSION).tar.gz $(PACKAGE)-$(VERSION)
	rm -rf $(PACKAGE)-$(VERSION)
	ls -l $(PACKAGE)-$(VERSION).tar.gz

check-manifest:
	@for d in `find -type d -name CVS | grep -v '^\./debian/'`; \
	do \
	b=`dirname $$d`/; \
	awk -F/ '$$1 != "D" {print $$2}' $$d/Entries | \
	sed -e "s|^|$$b|" -e "s|^\./||"; \
	done | sort > .check-manifest; \
	sort MANIFEST > .orig-manifest; \
	diff -u .orig-manifest .check-manifest; rv=$$?; \
	rm -f .orig-manifest .check-manifest; \
	exit $$rv
