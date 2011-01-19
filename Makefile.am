# Makefile for virt-what
# Copyright (C) 2008-2011 Red Hat Inc.
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

EXTRA_DIST = \
	virt-what.in \
	virt-what.pod \
	tests/baremetal/proc/cpuinfo \
	tests/baremetal/proc/self/status \
	tests/baremetal/sbin/dmidecode \
	tests/baremetal/sbin/id \
	tests/baremetal/sbin/virt-what-cpuid-helper \
	tests/esx4.1/proc/cpuinfo \
	tests/esx4.1/proc/self/status \
	tests/esx4.1/sbin/dmidecode \
	tests/esx4.1/sbin/id \
	tests/esx4.1/sbin/virt-what-cpuid-helper \
	tests/kvm/proc/cpuinfo \
	tests/kvm/proc/self/status \
	tests/kvm/sbin/dmidecode \
	tests/kvm/sbin/id \
	tests/kvm/sbin/virt-what-cpuid-helper \
	tests/qemu/proc/cpuinfo \
	tests/qemu/proc/self/status \
	tests/qemu/sbin/dmidecode \
	tests/qemu/sbin/id \
	tests/qemu/sbin/virt-what-cpuid-helper \
	tests/test-baremetal.sh \
	tests/test-esx4.1.sh \
	tests/test-kvm.sh \
	tests/test-qemu.sh

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

TESTS = \
	tests/test-baremetal.sh \
	tests/test-esx4.1.sh \
	tests/test-kvm.sh \
	tests/test-qemu.sh
# tests/test-virtualbox.sh \
# tests/test-xen-dom0.sh \
# tests/test-xen-domU.sh
