/**
 * @brief ラグランジュ補間 評価版
 * @docs docs/math/lagrange_interpolation.md
 */

#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
T lagrange_interpolation(const std::vector<T>& x, const std::vector<T>& y,
                         const T t) {
  const auto it = std::find(x.begin(), x.end(), t);
  if (it != x.end()) return y[std::distance(x.begin(), it)];
  const int n = x.size();
  T res = 0;
  for (int i = 0; i < n; ++i) {
    T den = t - x[i];
    for (int j = 0; j < n; ++j) {
      if (j != i) den *= x[i] - x[j];
    }
    res += y[i] / den;
  }
  for (int i = 0; i < n; ++i) {
    res *= t - x[i];
  }
  return res;
}
