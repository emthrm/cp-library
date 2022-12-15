#ifndef EMTHRM_MATH_CATALAN_NUMBER_HPP_
#define EMTHRM_MATH_CATALAN_NUMBER_HPP_

#include <vector>

#include "emthrm/math/modint.hpp"

namespace emthrm {

template <int T>
std::vector<MInt<T>> catalan_number(const int n) {
  using ModInt = MInt<T>;
  ModInt::inv(n + 1, true);
  std::vector<ModInt> c(n + 1);
  c[0] = 1;
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] * ModInt::inv(i + 2) * 2 * (2 * i + 1);
  }
  return c;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CATALAN_NUMBER_HPP_
