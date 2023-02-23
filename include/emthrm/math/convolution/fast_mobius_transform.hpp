#ifndef EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_
#define EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_

#include <bit>
#include <vector>

namespace emthrm {

template <bool ADDS_SUPERSET, typename T>
std::vector<T> fast_mobius_transform(std::vector<T> a, const T id = 0) {
  const int n = std::bit_ceil(a.size());
  a.resize(n, id);
  for (int i = 1; i < n; i <<= 1) {
    for (int s = 0; s < n; ++s) {
      if (s & i) continue;
      if constexpr (ADDS_SUPERSET) {
        a[s] -= a[s | i];
      } else {
        a[s | i] -= a[s];
      }
    }
  }
  return a;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_
