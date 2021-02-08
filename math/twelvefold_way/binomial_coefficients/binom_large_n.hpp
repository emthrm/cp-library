/**
 * @brief 二項係数 $n$ は巨大
 * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
 */

#pragma once
#include <cassert>
#include "../../modint.hpp"

ModInt binom_large_n(long long n, int k, const Combinatorics &com) {
  if (n < 0 || n < k || k < 0) return 0;
  assert(k <= com.val);
  ModInt res = 1;
  for (int i = 1; i <= k; ++i) res *= com.inv[i] * n--;
  return res;
}
