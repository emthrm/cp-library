#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_EULERIAN_NUMBER_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_EULERIAN_NUMBER_HPP_

#include <vector>

namespace emthrm {

template <typename T>
std::vector<std::vector<T>> eulerian_number(const int n, const int m) {
  std::vector<std::vector<T>> a(n + 1, std::vector<T>(m + 1, 0));
  a[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    a[i][0] = 1;
    for (int j = 1; j < i; ++j) {
      a[i][j] = a[i - 1][j - 1] * (i - j) + a[i - 1][j] * (j + 1);
    }
  }
  return a;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_EULERIAN_NUMBER_HPP_
