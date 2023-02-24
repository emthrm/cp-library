/**
 * @title 分割数 $n = m$ 版
 * @docs docs/math/twelvefold_way/partition_function.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_PARTITION_FUNCTION_BY_FPS_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_PARTITION_FUNCTION_BY_FPS_HPP_

#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"

namespace emthrm {

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

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_PARTITION_FUNCTION_BY_FPS_HPP_
