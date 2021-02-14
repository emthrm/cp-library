/**
 * @brief 二項係数 $n$ は巨大な固定値
 * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
 */

#pragma once
#include <algorithm>
#include <vector>
#include "../../modint.hpp"

template <int T>
std::vector<MInt<T>> binom_large_n_init(long long n, int k) {
  using ModInt = MInt<T>;
  int tmp = std::min(n, static_cast<long long>(k));
  ModInt::inv(tmp, true);
  std::vector<ModInt> c(k + 1, 0);
  c[0] = 1;
  for (int i = 1; i <= tmp; ++i) c[i] = c[i - 1] * n-- * ModInt::inv(i);
  return c;
}
