#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_BY_FPS_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_STIRLING_NUMBER_STIRLING_NUMBER_OF_THE_FIRST_KIND_INIT_BY_FPS_HPP_

#include <bit>
#include <cstdint>
#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"

namespace emthrm {

template <typename T>
std::vector<T> stirling_number_of_the_first_kind_init_by_fps(const int n) {
  if (n == 0) [[unlikely]] return {1};
  FormalPowerSeries<T> s{0, 1};
  for (int i = 30 - std::countl_zero(static_cast<std::uint32_t>(n));
       i >= 0; --i) {
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
