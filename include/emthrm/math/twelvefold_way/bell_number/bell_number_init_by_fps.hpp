/**
 * @brief ベル数の数表 $n = k$ 版
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_BY_FPS_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_BY_FPS_HPP_

#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"

namespace emthrm {

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

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_INIT_BY_FPS_HPP_
