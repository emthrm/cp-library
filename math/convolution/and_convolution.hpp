/**
 * @brief 添え字 and での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <vector>
#include "fast_zeta_transform.hpp"
#include "fast_mobius_transform.hpp"

template <typename T>
std::vector<T> and_convolution(const std::vector<T> &a, const std::vector<T> &b, const T ID = 0) {
  auto add = [](const T &a, const T &b) -> T { return a + b; };
  std::vector<T> fzt_a = fast_zeta_transform(a, true, ID, add), fzt_b = fast_zeta_transform(b, true, ID, add);
  int n = fzt_a.size();
  for (int i = 0; i < n; ++i) fzt_a[i] *= fzt_b[i];
  return fast_mobius_transform(fzt_a, true);
}
