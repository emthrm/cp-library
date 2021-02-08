/**
 * @brief 添え字 and での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <vector>
#include "fzt.hpp"
#include "fmt.hpp"

template <typename T>
std::vector<T> and_convolution(const std::vector<T> &a, const std::vector<T> &b, const T UNITY = 0) {
  auto add = [](const T &a, const T &b) -> T { return a + b; };
  std::vector<T> fzt_a = fzt(a, true, UNITY, add), fzt_b = fzt(b, true, UNITY, add);
  int n = fzt_a.size();
  for (int i = 0; i < n; ++i) fzt_a[i] *= fzt_b[i];
  return fmt(fzt_a, true);
}
