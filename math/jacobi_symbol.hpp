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
    int ex = __builtin_ctzll(a);
    if (ex & 1 && (p % 8 == 3 || p % 8 == 5)) res = -res;
    a >>= ex;
    if (a % 4 == 3 && p % 4 == 3) res = -res;
    std::swap(a, p);
    a %= p;
  }
  return p == 1 ? res : 0;
}
