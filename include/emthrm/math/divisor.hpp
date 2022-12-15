#ifndef EMTHRM_MATH_DIVISOR_HPP_
#define EMTHRM_MATH_DIVISOR_HPP_

#include <algorithm>
#include <vector>

namespace emthrm {

template <typename T>
std::vector<T> divisor(const T n) {
  std::vector<T> res;
  T i = 1;
  for (; i * i < n; ++i) {
    if (n % i == 0) {
      res.emplace_back(i);
      res.emplace_back(n / i);
    }
  }
  if (i * i == n && n % i == 0) res.emplace_back(i);
  std::sort(res.begin(), res.end());
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_DIVISOR_HPP_
