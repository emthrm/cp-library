#ifndef EMTHRM_DYNAMIC_PROGRAMMING_SUBSET_SUM_PROBLEM_HPP_
#define EMTHRM_DYNAMIC_PROGRAMMING_SUBSET_SUM_PROBLEM_HPP_

#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"

namespace emthrm {

template <typename T>
std::vector<T> subset_sum_problem(const std::vector<int>& a, const int d) {
  T zero = 1;
  std::vector<int> nums(d + 1, 0);
  for (const int e : a) {
    if (e == 0) {
      zero *= 2;
    } else if (e <= d) {
      ++nums[e];
    }
  }
  FormalPowerSeries<T> fps(d);
  for (int i = 1; i <= d; ++i) {
    for (int j = 1; i * j <= d; ++j) {
      fps[i * j] += static_cast<T>(nums[i]) / (j & 1 ? j : -j);
    }
  }
  return (fps.exp(d) * zero).coef;
}

}  // namespace emthrm

#endif  // EMTHRM_DYNAMIC_PROGRAMMING_SUBSET_SUM_PROBLEM_HPP_
