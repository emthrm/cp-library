#ifndef EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_
#define EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_

#include <bit>
#include <functional>
#include <vector>

namespace emthrm {

template <bool ADDS_SUPERSET, typename Ring>
std::vector<Ring> fast_zeta_transform(
    std::vector<Ring> a, const Ring ID = 0,
    const std::function<Ring(const Ring&, const Ring&)> fn =
        [](const Ring& a, const Ring& b) -> Ring { return a + b; }) {
  const int n = std::bit_ceil(a.size());
  a.resize(n, ID);
  for (int i = 1; i < n; i <<= 1) {
    for (int s = 0; s < n; ++s) {
      if (s & i) continue;
      if constexpr (ADDS_SUPERSET) {
        a[s] = fn(a[s], a[s | i]);
      } else {
        a[s | i] = fn(a[s | i], a[s]);
      }
    }
  }
  return a;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_
