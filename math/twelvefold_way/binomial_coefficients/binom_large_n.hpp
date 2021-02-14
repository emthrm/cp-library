/**
 * @brief 二項係数 $n$ は巨大
 * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
 */

#pragma once
#include <cassert>
#include "../../modint.hpp"

template <int T>
MInt<T> binom_large_n(long long n, int k) {
  using ModInt = MInt<T>;
  if (n < 0 || n < k || k < 0) return 0;
  ModInt::inv(k, true);
  ModInt res = 1;
  for (int i = 1; i <= k; ++i) res *= ModInt::inv(i) * n--;
  return res;
}
