/**
 * @brief ヤコビ記号
 * @docs docs/math/quadratic_residue.md
 */

#ifndef EMTHRM_MATH_JACOBI_SYMBOL_HPP_
#define EMTHRM_MATH_JACOBI_SYMBOL_HPP_

#include <cassert>
#include <utility>

#if !defined(__GNUC__) && \
    (!defined(__has_builtin) || !__has_builtin(__builtin_ctzll))
# error "__builtin_ctzll is required."
#endif

namespace emthrm {

int jacobi_symbol(long long a, long long p) {
  assert(p > 0 && p & 1);
  if (p == 1) [[unlikely]] return 1;
  if ((a %= p) < 0) a += p;
  if (a == 0) [[unlikely]] return 0;
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

}  // namespace emthrm

#endif  // EMTHRM_MATH_JACOBI_SYMBOL_HPP_
