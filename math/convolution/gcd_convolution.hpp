/**
 * @brief 添え字 gcd での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <algorithm>
#include <vector>

template <typename T>
std::vector<T> gcd_convolution(std::vector<T> a, std::vector<T> b) {
  const int n = std::max(a.size(), b.size());
  const auto transform = [n](std::vector<T>* v) -> void {
    for (int i = 1; i < n; ++i) {
      for (int j = i << 1; j < n; j += i) {
        (*v)[i] += (*v)[j];
      }
    }
  };
  a.resize(n, 0);
  transform(&a);
  b.resize(n, 0);
  transform(&b);
  for (int i = 1; i < n; ++i) {
    a[i] *= b[i];
  }
  for (int i = n - 1; i >= 1; --i) {
    for (int j = i << 1; j < n; j += i) {
      a[i] -= a[j];
    }
  }
  return a;
}
