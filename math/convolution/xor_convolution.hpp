/**
 * @brief 添え字 xor での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <algorithm>
#include <vector>

template <typename T>
std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b, const T ID = 0) {
  int n = std::max(a.size(), b.size()), p = 1;
  while ((1 << p) < n) {
    ++p;
  }
  n = 1 << p;
  a.resize(n, ID);
  b.resize(n, ID);
  auto fwht = [n](std::vector<T> &v) -> void {
    for (int i = 1; i < n; i <<= 1) {
      for (int s = 0; s < n; ++s) {
        if (s & i) continue;
        T tmp1 = v[s], tmp2 = v[s | i];
        v[s] = tmp1 + tmp2;
        v[s | i] = tmp1 - tmp2;
      }
    }
  };
  fwht(a);
  fwht(b);
  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  fwht(a);
  for (int i = 0; i < n; ++i) {
    a[i] /= n;
  }
  return a;
}
