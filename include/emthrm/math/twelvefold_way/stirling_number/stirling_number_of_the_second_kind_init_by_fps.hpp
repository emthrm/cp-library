/**
 * @brief 第2種スターリング数の数表 形式的冪級数版
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md
 */

#pragma once
#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"
#include "emthrm/math/modint.hpp"

template <int T>
std::vector<MInt<T>> stirling_number_of_the_second_kind_init_by_fps(
    const int n) {
  using ModInt = MInt<T>;
  ModInt::init(n);
  FormalPowerSeries<ModInt> a(n), b(n);
  for (int i = 0; i <= n; ++i) {
    a[i] = ModInt(i).pow(n) * ModInt::fact_inv(i);
  }
  for (int i = 0; i <= n; ++i) {
    b[i] = (i & 1 ? -ModInt::fact_inv(i) : ModInt::fact_inv(i));
  }
  a *= b;
  a.resize(n);
  return a.coef;
}
