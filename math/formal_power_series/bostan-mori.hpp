/**
 * @brief Bostan–Mori のアルゴリズム
 * @docs docs/math/formal_power_series/bostan-mori.md
 */

#pragma once
#include <cassert>

template <template <typename> class C, typename T>
T bostan_mori(C<T> p, C<T> q, long long n) {
  q.shrink();
  const int d = q.degree();
  assert(d >= 0 && q[0] != 0);
  T res = 0;
  p.shrink();
  if (p.degree() >= d) {
    const C<T> quotient = p / q;
    p -= quotient * q;
    p.shrink();
    if (n <= quotient.degree()) res += quotient[n];
  }
  if (d == 0 || (p.degree() == 0 && p[0] == 0)) return res;
  p.resize(d - 1);
  for (; n > 0; n >>= 1) {
    C<T> tmp = q;
    for (int i = 1; i <= d; i += 2) {
      tmp[i] = -tmp[i];
    }
    p *= tmp;
    if (n & 1) {
      for (int i = 0; i < d; ++i) {
        p[i] = p[(i << 1) + 1];
      }
    } else {
      for (int i = 1; i < d; ++i) {
        p[i] = p[i << 1];
      }
    }
    p.resize(d - 1);
    q *= tmp;
    for (int i = 1; i <= d; ++i) {
      q[i] = q[i << 1];
    }
    q.resize(d);
  }
  return res + p[0] / q[0];
}
