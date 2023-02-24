/**
 * @title 二項係数の数表 巨大な $n$ 版
 * @docs docs/math/twelvefold_way/binomial_coefficients.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_LARGE_NCK_INIT_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_LARGE_NCK_INIT_HPP_

#include <algorithm>
#include <vector>

#include "emthrm/math/modint.hpp"

namespace emthrm {

template <int T>
std::vector<MInt<T>> large_nCk_init(long long n, const int k) {
  using ModInt = MInt<T>;
  const int tmp = std::min(n, static_cast<long long>(k));
  ModInt::template inv<true>(tmp);
  std::vector<ModInt> c(k + 1, 0);
  c.front() = 1;
  for (int i = 1; i <= tmp; ++i) {
    c[i] = c[i - 1] * n-- * ModInt::inv(i);
  }
  return c;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_LARGE_NCK_INIT_HPP_
