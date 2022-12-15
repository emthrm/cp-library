/**
 * @brief 添え字 and での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#ifndef EMTHRM_MATH_CONVOLUTION_AND_CONVOLUTION_HPP_
#define EMTHRM_MATH_CONVOLUTION_AND_CONVOLUTION_HPP_

#include <algorithm>
#include <vector>

#include "emthrm/math/convolution/fast_mobius_transform.hpp"
#include "emthrm/math/convolution/fast_zeta_transform.hpp"

namespace emthrm {

template <typename T>
std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b,
                               const T id = 0) {
  int n = std::max(a.size(), b.size());
  a.resize(n, id);
  b.resize(n, id);
  a = fast_zeta_transform(a, true, id);
  b = fast_zeta_transform(b, true, id);
  n = a.size();
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  return fast_mobius_transform(a, true);
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_AND_CONVOLUTION_HPP_
