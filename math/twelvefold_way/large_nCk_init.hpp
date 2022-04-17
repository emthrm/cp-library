/**
 * @brief 二項係数の数表 巨大な $n$ 版
 * @docs docs/math/twelvefold_way/binomial_coefficients.md
 */

#pragma once
#include <algorithm>
#include <vector>

#include "../modint.hpp"

template <int T>
std::vector<MInt<T>> large_nCk_init(long long n, const int k) {
  using ModInt = MInt<T>;
  const int tmp = std::min(n, static_cast<long long>(k));
  ModInt::inv(tmp, true);
  std::vector<ModInt> c(k + 1, 0);
  c.front() = 1;
  for (int i = 1; i <= tmp; ++i) {
    c[i] = c[i - 1] * n-- * ModInt::inv(i);
  }
  return c;
}
