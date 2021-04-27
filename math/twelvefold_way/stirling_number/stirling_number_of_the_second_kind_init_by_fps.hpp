/**
 * @brief 第2種スターリング数の数表 形式的冪級数版
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md
 */

#pragma once
#include <vector>
#include "../../modint.hpp"
#include "../../formal_power_series/formal_power_series.hpp"

template <int T>
std::vector<MInt<T>> stirling_number_of_the_second_kind_init_by_fps(int n) {
  using ModInt = MInt<T>;
  ModInt::init(n);
  FormalPowerSeries<ModInt> a(n), b(n);
  for (int i = 0; i <= n; ++i) a[i] = ModInt(i).pow(n) * ModInt::fact_inv(i);
  for (int i = 0; i <= n; ++i) b[i] = ModInt::fact_inv(i) * (i & 1 ? -1 : 1);
  a *= b;
  a.co.resize(n + 1);
  return a.co;
}
