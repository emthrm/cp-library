#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_BERNOULLI_NUMBER_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_BERNOULLI_NUMBER_HPP_

#include <vector>

#include "emthrm/math/formal_power_series/formal_power_series.hpp"

namespace emthrm {

template <typename T>
std::vector<T> bernoulli_number(const int n) {
  FormalPowerSeries<T> bernoulli(n);
  bernoulli[0] = 1;
  for (int i = 1; i <= n; ++i) {
    bernoulli[i] = bernoulli[i - 1] / (i + 1);
  }
  bernoulli = bernoulli.inv(n);
  T fact = 1;
  for (int i = 0; i <= n; ++i) {
    bernoulli[i] *= fact;
    fact *= i + 1;
  }
  return bernoulli.coef;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_BERNOULLI_NUMBER_HPP_
