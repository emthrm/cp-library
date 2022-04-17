/**
 * @brief ラグランジュ補間 評価版2
 * @docs docs/math/lagrange_interpolation.md
 */

#pragma once
#include <cassert>
#include <vector>

template <typename T>
T lagrange_interpolation(const std::vector<T>& y, const T t) {
  const int n = y.size();
  assert(t < 0 || t >= n);
  std::vector<T> fact(n, 1);
  for (int i = 1; i < n; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  T res = 0;
  for (int i = 0; i < n; ++i) {
    res += ((n - 1 - i) & 1 ? -y[i] : y[i])
           / ((t - i) * fact[i] * fact[n - 1 - i]);
  }
  for (int i = 0; i < n; ++i) res *= t - i;
  return res;
}
