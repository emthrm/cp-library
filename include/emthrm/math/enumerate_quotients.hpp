#ifndef EMTHRM_MATH_ENUMERATE_QUOTIENTS_HPP_
#define EMTHRM_MATH_ENUMERATE_QUOTIENTS_HPP_

#include <tuple>
#include <vector>

namespace emthrm {

template <typename T>
std::vector<std::tuple<T, T, T>> enumerate_quotients(const T n) {
  std::vector<std::tuple<T, T, T>> quotients;
  for (T l = 1; l <= n;) {
    const T quotient = n / l, r = n / quotient + 1;
    quotients.emplace_back(l, r, quotient);
    l = r;
  }
  return quotients;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_ENUMERATE_QUOTIENTS_HPP_
