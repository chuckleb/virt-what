# Makefile for virt-what
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

EXTRA_DIST = virt-what.in virt-what.pod

CLEANFILES = virt-what.1 virt-what.txt

AM_CPPFLAGS = -Wall

sbin_SCRIPTS = virt-what
libexec_PROGRAMS = virt-what-cpuid-helper

man_MANS = virt-what.1

virt-what.1: virt-what.pod
	pod2man -c "Virtualization Support" --release "$(PACKAGE)-$(VERSION)" \
	  $< > $@

virt-what.txt: virt-what.pod
	pod2text $< > $@
