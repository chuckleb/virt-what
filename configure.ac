# virt-what
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

AC_INIT([virt-what],[1.13])
AM_INIT_AUTOMAKE([foreign])

dnl Check for basic C environment.
AC_PROG_CC_STDC
AC_PROG_INSTALL
AC_PROG_CPP

AC_C_PROTOTYPES
test "x$U" != "x" && AC_MSG_ERROR([Compiler not ANSI compliant])

AM_PROG_CC_C_O

dnl Architecture we are compiling for.
AC_CANONICAL_HOST
AM_CONDITIONAL([HOST_CPU_IA64], [ test "x$host_cpu" = "xia64" ])

dnl Produce output files.
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([virt-what],[chmod +x virt-what])
AC_CONFIG_FILES([Makefile])

AC_CHECK_PROG([POD2MAN], [pod2man], [pod2man], [false])
if test "$POD2MAN" = "false"; then
    AC_MSG_WARN([pod2man was not found.  This is needed to build man pages.])
fi
AM_CONDITIONAL([HAVE_POD2MAN], [test "$POD2MAN" != "false"])

AC_OUTPUT
