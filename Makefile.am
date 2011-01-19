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
	tests/linux-vserver/proc/cpuinfo \
	tests/linux-vserver/proc/self/status \
	tests/linux-vserver/sbin/dmidecode \
	tests/linux-vserver/sbin/id \
	tests/linux-vserver/sbin/virt-what-cpuid-helper \
	tests/qemu/proc/cpuinfo \
	tests/qemu/proc/self/status \
	tests/qemu/sbin/dmidecode \
	tests/qemu/sbin/id \
	tests/qemu/sbin/virt-what-cpuid-helper \
	tests/rhel5-xen-dom0/proc/cpuinfo \
	tests/rhel5-xen-dom0/proc/self/status \
	tests/rhel5-xen-dom0/proc/xen/balloon \
	tests/rhel5-xen-dom0/proc/xen/capabilities \
	tests/rhel5-xen-dom0/proc/xen/privcmd \
	tests/rhel5-xen-dom0/proc/xen/xenbus \
	tests/rhel5-xen-dom0/proc/xen/xsd_kva \
	tests/rhel5-xen-dom0/proc/xen/xsd_port \
	tests/rhel5-xen-dom0/sbin/dmidecode \
	tests/rhel5-xen-dom0/sbin/id \
	tests/rhel5-xen-dom0/sbin/virt-what-cpuid-helper \
	tests/rhel5-xen-domU-hvm/proc/cpuinfo \
	tests/rhel5-xen-domU-hvm/proc/self/status \
	tests/rhel5-xen-domU-hvm/sbin/dmidecode \
	tests/rhel5-xen-domU-hvm/sbin/id \
	tests/rhel5-xen-domU-hvm/sbin/virt-what-cpuid-helper \
	tests/rhel5-xen-domU-pv/proc/cpuinfo \
	tests/rhel5-xen-domU-pv/proc/self/status \
	tests/rhel5-xen-domU-pv/proc/xen/balloon \
	tests/rhel5-xen-domU-pv/proc/xen/capabilities \
	tests/rhel5-xen-domU-pv/proc/xen/privcmd \
	tests/rhel5-xen-domU-pv/proc/xen/xenbus \
	tests/rhel5-xen-domU-pv/sbin/dmidecode \
	tests/rhel5-xen-domU-pv/sbin/id \
	tests/rhel5-xen-domU-pv/sbin/virt-what-cpuid-helper \
	tests/test-baremetal.sh \
	tests/test-esx4.1.sh \
	tests/test-kvm.sh \
	tests/test-linux-vserver.sh \
	tests/test-qemu.sh \
	tests/test-rhel5-xen-dom0.sh \
	tests/test-rhel5-xen-domU-hvm.sh \
	tests/test-rhel5-xen-domU-pv.sh

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
	tests/test-linux-vserver.sh \
	tests/test-qemu.sh \
	tests/test-rhel5-xen-dom0.sh \
	tests/test-rhel5-xen-domU-hvm.sh \
	tests/test-rhel5-xen-domU-pv.sh
