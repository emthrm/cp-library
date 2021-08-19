/**
 * @brief 添え字 and での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <algorithm>
#include <vector>
#include "fast_zeta_transform.hpp"
#include "fast_mobius_transform.hpp"

template <typename T>
std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b, const T ID = 0) {
  int n = std::max(a.size(), b.size());
  a.resize(n, ID);
  b.resize(n, ID);
  std::vector<T> fzt_a = fast_zeta_transform(a, true, ID), fzt_b = fast_zeta_transform(b, true, ID);
  n = fzt_a.size();
  for (int i = 0; i < n; ++i) fzt_a[i] *= fzt_b[i];
  return fast_mobius_transform(fzt_a, true);
}
