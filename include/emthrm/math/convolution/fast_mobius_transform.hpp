#ifndef EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_
#define EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_

#include <vector>

namespace emthrm {

template <typename T>
std::vector<T> fast_mobius_transform(std::vector<T> a,
                                     const bool adds_superset, const T id = 0) {
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, id);
  if (adds_superset) {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        a[s] -= a[s | i];
      }
    }
  } else {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        a[s | i] -= a[s];
      }
    }
  }
  return a;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_FAST_MOBIUS_TRANSFORM_HPP_
