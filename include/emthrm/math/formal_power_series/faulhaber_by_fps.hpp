/**
 * @brief ファウルハーバーの公式 形式的冪級数版
 * @docs docs/math/formal_power_series/faulhaber.md
 */

#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_

#include <cassert>
#include <vector>

#include "emthrm/math/formal_power_series/bernoulli_number.hpp"
#include "emthrm/math/modint.hpp"

namespace emthrm {

template <int T>
MInt<T> faulhaber_by_fps(const long long n, const int k) {
  using ModInt = MInt<T>;
  if (n <= 1) return 0;
  if (k == 0) return n - 1;
  ModInt::init(k + 1);
  const std::vector<ModInt> bernoulli = bernoulli_number<ModInt>(k);
  ModInt res = 0, p = 1;
  for (int i = k; i >= 0; --i) {
    p *= n;
    res += ModInt::nCk(k + 1, i) * bernoulli[i] * p;
  }
  return res / (k + 1);
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_FAULHABER_BY_FPS_HPP_
