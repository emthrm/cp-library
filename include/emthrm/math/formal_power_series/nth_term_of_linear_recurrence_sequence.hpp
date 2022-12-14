/**
 * @brief 線形回帰数列の第 $N$ 項
 * @docs docs/math/formal_power_series/bostan-mori.md
 */

#pragma once
#include <cassert>

#include "emthrm/math/formal_power_series/bostan-mori.hpp"

template <template <typename> class C, typename T>
T nth_term_of_linear_recurrence_sequence(C<T> a, C<T> q, const long long n) {
  q.shrink();
  const int d = q.degree();
  assert(d >= 0 && q[0] != 0);
  if (a.degree() >= n) return a[n];
  assert(a.degree() >= d - 1);
  a.resize(d - 1);
  a *= q;
  a.resize(d - 1);
  return bostan_mori(a, q, n);
}
