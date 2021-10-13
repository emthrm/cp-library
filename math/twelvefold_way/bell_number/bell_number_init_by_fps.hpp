/**
 * @brief ベル数の数表 $n = k$ 版
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#pragma once
#include <vector>
#include "../../formal_power_series/formal_power_series.hpp"

template <typename T>
std::vector<T> bell_number_init_by_fps(const int n) {
  FormalPowerSeries<T> b(n);
  b[1] = 1;
  b = b.exp(n);
  b[0] -= 1;
  b = b.exp(n);
  T fact = 1;
  for (int i = 0; i <= n; ++i) {
    b[i] *= fact;
    fact *= i + 1;
  }
  return b.coef;
}
