#ifndef EMTHRM_MATH_CONVOLUTION_EXP_OF_SET_POWER_SERIES_HPP_
#define EMTHRM_MATH_CONVOLUTION_EXP_OF_SET_POWER_SERIES_HPP_

#include <algorithm>
#include <bit>
#include <cassert>
#include <iterator>
#include <vector>

#include "emthrm/math/convolution/subset_convolution.hpp"

namespace emthrm {

template <int MaxN, typename T>
std::vector<T> exp_of_set_power_series(const std::vector<T>& f) {
  assert(std::has_single_bit(f.size()) && f[0] == 0);
  const int n = std::countr_zero(f.size());
  assert(n <= MaxN);
  std::vector<T> exponential{1};
  exponential.reserve(1 << n);
  for (int i = 0; i < n; ++i) {
    std::ranges::copy(subset_convolution<MaxN>(
                          exponential,
                          std::vector(std::next(f.begin(), 1 << i),
                                      std::next(f.begin(), 1 << (i + 1)))),
                      std::back_inserter(exponential));
  }
  return exponential;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_EXP_OF_SET_POWER_SERIES_HPP_
