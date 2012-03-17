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

static unsigned int
cpuid (unsigned int eax, char *sig)
{
  unsigned int *sig32 = (unsigned int *) sig;

  asm volatile (
        "xchgl %%ebx,%1; xor %%ebx,%%ebx; cpuid; xchgl %%ebx,%1"
        : "=a" (eax), "+r" (sig32[0]), "=c" (sig32[1]), "=d" (sig32[2])
        : "0" (eax));
  sig[12] = 0;

  return eax;
}

static void
cpu_sig (void)
{
  char sig[13];
  unsigned int base = 0x40000000, leaf = base;
  unsigned int max_entries;

  memset (sig, 0, sizeof sig);
  max_entries = cpuid (leaf, sig);
  puts (sig);

  /* Most hypervisors only have information in leaf 0x40000000, but
   * upstream Xen contains further leaf entries (in particular when
   * used with Viridian [HyperV] extensions).  CPUID is supposed to
   * return the maximum leaf offset in %eax, so that's what we use,
   * but only if it looks sensible.
   */
  if (max_entries > 3 && max_entries < 0x10000) {
    for (leaf = base + 0x100; leaf <= base + max_entries; leaf += 0x100) {
      memset (sig, 0, sizeof sig);
      cpuid (leaf, sig);
      puts (sig);
    }
  }
}

#else /* !i386, !x86_64 */

static void
cpu_sig (void)
{
  /* nothing for other architectures */
}

#endif

int
main()
{
  cpu_sig ();
  return 0;
}
