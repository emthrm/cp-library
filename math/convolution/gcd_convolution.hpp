/**
 * @brief 添え字 gcd での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <vector>

template <typename T>
std::vector<T> gcd_convolution(const std::vector<T> &a, const std::vector<T> &b) {
  int n = a.size();
  auto zeta = [&](std::vector<T> v) -> std::vector<T> {
    for (int i = 1; i < n; ++i) {
      for (int j = i << 1; j < n; j += i) v[i] += v[j];
    }
    return v;
  };
  std::vector<T> zeta_a = zeta(a), zeta_b = zeta(b);
  for (int i = 1; i < n; ++i) zeta_a[i] *= zeta_b[i];
  for (int i = n - 1; i >= 1; --i) {
    for (int j = i << 1; j < n; j += i) zeta_a[i] -= zeta_a[j];
  }
  return zeta_a;
}
