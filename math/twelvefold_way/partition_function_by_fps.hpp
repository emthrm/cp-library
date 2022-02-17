/**
 * @brief 分割数 $n = m$ 版
 * @docs docs/math/twelvefold_way/partition_function.md
 */

#pragma once
#include <vector>

#include "../formal_power_series/formal_power_series.hpp"

template <typename T>
std::vector<T> partition_function_by_fps(const int n) {
  FormalPowerSeries<T> fps(n);
  fps[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int idx = (3 * i - 1) * i / 2;
    if (idx > n) break;
    fps[idx] = (i & 1 ? -1 : 1);
    idx = (3 * i + 1) * i / 2;
    if (idx <= n) fps[idx] = (i & 1 ? -1 : 1);
  }
  return fps.inv(n).coef;
}
