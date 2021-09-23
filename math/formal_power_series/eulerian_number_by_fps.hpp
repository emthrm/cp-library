/**
 * @brief Eulerian number 形式的冪級数版
 * @docs docs/math/formal_power_series/eulerian_number.md
 */

#pragma once
#include <vector>
#include "../modint.hpp"
#include "formal_power_series.hpp"

template <int T>
std::vector<MInt<T>> eulerian_number_init_by_fps(const int n) {
  using ModInt = MInt<T>;
  if (n == 0) return {1};
  ModInt::init(n + 1);
  const int m = (n + 1) >> 1;
  FormalPowerSeries<ModInt> a(m - 1), b(m - 1);
  for (int i = 0; i < m; ++i) {
    a[i] = ModInt(i + 1).pow(n);
  }
  for (int i = 0; i < m; ++i) {
    b[i] = ModInt::fact_inv(i) * ModInt::fact_inv(n + 1 - i) * (i & 1 ? -1 : 1);
  }
  a *= b;
  a.resize(n);
  for (int i = 0; i < m; ++i) {
    a[i] *= ModInt::fact(n + 1);
    a[n - 1 - i] = a[i];
  }
  return a.co;
}
