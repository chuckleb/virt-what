/* virt-what-ia64-xen-rdtsc-test
 * Copyright (C) 2011 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __ia64__
#error "error in Makefile - this program should only be compiled for ia64 host"
#endif

/* This program is ugly, but possibly the only way to detect
 * virtualized Xen HVM guests on IA64.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline unsigned long
rdtsc (void)
{
  unsigned long res;
  asm volatile ("mov %0=ar.itc" : "=r"(res));
  return res;
}

int
main ()
{
  unsigned long old, new;
  int virt;
  int i;

  virt = 1;

  for (i = 16; i--; ) {
    old = rdtsc (); new = rdtsc ();
    /*printf("%ld\n", new - old);*/
    if (new - old < 30) {
      virt = 0;
      break;
    }
  }

  exit (virt);
}
