/**
 * @brief ヤコビ記号
 * @docs docs/math/quadratic_residue.md
 */

#pragma once
#include <cassert>
#include <utility>

int jacobi_symbol(long long a, long long p) {
  assert(p > 0 && p & 1);
  if (p == 1) return 1;
  if ((a %= p) < 0) a += p;
  if (a == 0) return 0;
  int res = 1;
  while (a > 0) {
    const int p2 = __builtin_ctzll(a);
    if ((p2 & 1) && ((p + 2) & 4)) res = -res;
    a >>= p2;
    if (a & p & 2) res = -res;
    std::swap(a, p);
    a %= p;
  }
  return p == 1 ? res : 0;
}
