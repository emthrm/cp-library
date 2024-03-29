#ifndef EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_
#define EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_

#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <vector>

namespace emthrm {

template <typename T>
T lagrange_interpolation(const std::vector<T>& x, const std::vector<T>& y,
                         const T t) {
  const auto it = std::find(x.begin(), x.end(), t);
  if (it != x.end()) return y[std::distance(x.begin(), it)];
  const int n = x.size();
  T res = 0;
  for (int i = 0; i < n; ++i) {
    T den = t - x[i];
    for (int j = 0; j < n; ++j) {
      if (j != i) den *= x[i] - x[j];
    }
    res += y[i] / den;
  }
  return std::transform_reduce(
      x.begin(), x.end(), res, std::multiplies<T>(),
      [t](const T& x_i) -> T { return t - x_i; });
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_LAGRANGE_INTERPOLATION_HPP_
