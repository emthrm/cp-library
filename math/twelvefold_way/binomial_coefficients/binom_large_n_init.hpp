/**
 * @brief 二項係数 $n$ は巨大な固定値
 * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
 */

#pragma once
#include <algorithm>
#include <vector>
#include "../../modint.hpp"

std::vector<ModInt> binom_large_n_init(long long n, int k, const Combinatorics &com) {
  int tmp = std::min(n, static_cast<long long>(k));
  assert(tmp <= com.val);
  std::vector<ModInt> c(k + 1, 0);
  c[0] = 1;
  for (int i = 1; i <= tmp; ++i) c[i] = c[i - 1] * n-- * com.inv[i];
  return c;
}
