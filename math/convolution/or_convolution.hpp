/**
 * @brief 添え字 or での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <vector>
#include "fzt.hpp"
#include "fmt.hpp"

template <typename T>
std::vector<T> or_convolution(const std::vector<T> &a, const std::vector<T> &b, const T ID = 0) {
  std::vector<T> fzt_a = fzt(a, false, ID), fzt_b = fzt(b, false, ID);
  int n = fzt_a.size();
  for (int i = 0; i < n; ++i) fzt_a[i] *= fzt_b[i];
  return fmt(fzt_a, false);
}
