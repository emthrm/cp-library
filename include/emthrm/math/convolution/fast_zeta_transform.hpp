#ifndef EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_
#define EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_

#include <functional>
#include <vector>

namespace emthrm {

template <typename Ring, typename BinOp = std::plus<Ring>>
std::vector<Ring> fast_zeta_transform(
    std::vector<Ring> a, const bool adds_superset,
    const Ring ID = 0, const BinOp bin_op = BinOp()) {
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, ID);
  if (adds_superset) {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        a[s] = bin_op(a[s], a[s | i]);
      }
    }
  } else {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        a[s | i] = bin_op(a[s | i], a[s]);
      }
    }
  }
  return a;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_FAST_ZETA_TRANSFORM_HPP_
