#ifndef EMTHRM_MATH_EXT_GCD_HPP_
#define EMTHRM_MATH_EXT_GCD_HPP_

#include <tuple>
#include <utility>

namespace emthrm {

template <typename T>
std::pair<T, T> ext_gcd(T a, T b) {
  T x = 1, y = 0;
  for (T u = 0, v = 1; b;) {
    const T q = a / b;
    std::swap(a -= q * b, b);
    std::swap(x -= q * u, u);
    std::swap(y -= q * v, v);
  }
  return a < 0 ? std::make_pair(-x, -y) : std::make_pair(x, y);
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_EXT_GCD_HPP_
