/**
 * @brief 平方剰余
 * @docs docs/math/quadratic_residue.md
 */

#pragma once
#include "mod_pow.hpp"
#include "../util/xorshift.hpp"

long long mod_sqrt(long long a, int p) {
  if ((a %= p) < 0) a += p;
  if (a == 0) return 0;
  if (p == 2) return 1;
  int half_p = (p - 1) >> 1;
  if (mod_pow(a, half_p, p) == p - 1) return -1;
  if (p % 4 == 3) return mod_pow(a, (p + 1) >> 2, p);
  int s = 1, q = half_p;
  for (; !(q & 1); q >>= 1, ++s);
  long long z;
  do {
    z = xor128.rand(2, p);
  } while (mod_pow(z, half_p, p) == 1);
  int m = s;
  long long c = mod_pow(z, q, p), r = mod_pow(a, (q - 1) >> 1, p), t = a * r % p * r % p;
  (r *= a) %= p;
  while (t != 1) {
    long long t2 = t * t % p;
    for (int i = 1; i < m; ++i) {
      if (t2 == 1) {
        long long b = mod_pow(c, 1 << (m - i - 1), p);
        m = i;
        (r *= b) %= p;
        c = b * b % p;
        (t *= c) %= p;
        break;
      }
      (t2 *= t2) %= p;
    }
  }
  return r;
}
