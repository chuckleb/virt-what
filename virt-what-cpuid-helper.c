/* virt-what-cpuid-helper: Are we running inside KVM or Xen HVM?
 * Copyright (C) 2008 Red Hat Inc.
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

/* This program was suggested by Gleb Natapov and written by Paolo
 * Bonzini, with a few modifications by Richard W.M. Jones.
 */

#include <stdio.h>
#include <string.h>

#if defined(__i386__) || defined(__x86_64__)
void
cpu_sig (char *sig)
{
  unsigned int eax = 0x40000000;
  unsigned int *sig32 = (unsigned int *)sig;
  asm volatile (
        "xor %%ebx, %%ebx; cpuid"
        : "=a" (eax), "=b" (sig32[0]), "=c" (sig32[1]), "=d" (sig32[2])
        : "0" (eax));
  sig[12] = 0;
}
#else
void
cpu_sig (char *sig)
{
  /* nothing for other architectures */
}
#endif

int
main()
{
  char sig[13];

  memset (sig, 0, sizeof sig);

  cpu_sig (sig);

  puts (sig);
  /* Possible values:
   * KVMKVMKVM     KVM guest
   * XenVMMXenVMM  Xen HVM guest
   * VMwareVMware  VMware guest
   */

  return 0;
}
