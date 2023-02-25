#ifndef EMTHRM_MATH_CONVOLUTION_XOR_CONVOLUTION_HPP_
#define EMTHRM_MATH_CONVOLUTION_XOR_CONVOLUTION_HPP_

#include <algorithm>
#include <bit>
#include <vector>

namespace emthrm {

template <typename T>
std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b,
                               const T id = 0) {
  const int n = std::bit_ceil(std::max(a.size(), b.size()));
  const auto fast_walsh_hadamard_transform = [n](std::vector<T>* v) -> void {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        const T tmp1 = (*v)[s], tmp2 = (*v)[s | i];
        (*v)[s] = tmp1 + tmp2;
        (*v)[s | i] = tmp1 - tmp2;
      }
    }
  };
  a.resize(n, id);
  fast_walsh_hadamard_transform(&a);
  b.resize(n, id);
  fast_walsh_hadamard_transform(&b);
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  fast_walsh_hadamard_transform(&a);
  for (int i = 0; i < n; ++i) {
    a[i] /= n;
  }
  return a;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_CONVOLUTION_XOR_CONVOLUTION_HPP_
