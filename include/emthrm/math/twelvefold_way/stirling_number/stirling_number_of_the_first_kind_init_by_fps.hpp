/**
 * @brief 第1種スターリング数の数表 形式的冪級数版
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_BY_FPS_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_BY_FPS_HPP_

#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"

namespace emthrm {

template <typename T>
std::vector<T> stirling_number_of_the_first_kind_init_by_fps(const int n) {
  if (n == 0) return {1};
  FormalPowerSeries<T> s{0, 1};
  for (int i = 30 - __builtin_clz(n); i >= 0; --i) {
    s *= s.translate(-s.degree());
    if (n >> i & 1) {
      const int deg = s.degree();
      s <<= 1;
      for (int i = 0; i <= deg; ++i) {
        s[i] += s[i + 1] * -deg;
      }
    }
  }
  return s.coef;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_BY_FPS_HPP_
