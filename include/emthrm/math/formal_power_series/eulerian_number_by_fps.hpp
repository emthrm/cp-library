/**
 * @title Eulerian number 形式的冪級数版
 * @docs docs/math/formal_power_series/eulerian_number.md
 */

#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_EULERIAN_NUMBER_BY_FPS_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_EULERIAN_NUMBER_BY_FPS_HPP_

#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/modint.hpp"

namespace emthrm {

template <int T>
std::vector<MInt<T>> eulerian_number_init_by_fps(const int n) {
  using ModInt = MInt<T>;
  if (n == 0) [[unlikely]] return {1};
  ModInt::init(n + 1);
  const int m = (n + 1) >> 1;
  FormalPowerSeries<ModInt> a(m - 1), b(m - 1);
  for (int i = 0; i < m; ++i) {
    a[i] = ModInt(i + 1).pow(n);
  }
  for (int i = 0; i < m; ++i) {
    b[i] = (i & 1 ? -ModInt::fact_inv(i) : ModInt::fact_inv(i))
           * ModInt::fact_inv(n + 1 - i);
  }
  a *= b;
  a.resize(n);
  for (int i = 0; i < m; ++i) {
    a[i] *= ModInt::fact(n + 1);
    a[n - 1 - i] = a[i];
  }
  return a.coef;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_EULERIAN_NUMBER_BY_FPS_HPP_
