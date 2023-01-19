/**
 * @brief 添え字 lcm での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#ifndef EMTHRM_MATH_CONVOLUTION_LCM_CONVOLUTION_HPP_
#define EMTHRM_MATH_CONVOLUTION_LCM_CONVOLUTION_HPP_

#include <vector>

namespace emthrm {

template <typename T>
std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b,
                               const int n = -1) {
  if (n == -1) return lcm_convolution(a, b, (a.size() - 1) * (b.size() - 1));
  a.resize(n + 1, 0);
  b.resize(n + 1, 0);
  const auto transform = [n](std::vector<T>* v) -> void {
    for (int i = n; i >= 1; --i) {
      for (int j = i << 1; j <= n; j += i) {
        (*v)[j] += (*v)[i];
      }
    }
  };
  transform(&a);
  transform(&b);
  for (int i = 1; i <= n; ++i) {
    a[i] *= b[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i << 1; j <= n; j += i) {
      a[j] -= a[i];
    }
  }
  return a;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_LCM_CONVOLUTION_HPP_
