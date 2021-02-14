/**
 * @brief ファウルハーバーの公式 ラグランジュ補間版
 * @docs docs/math/fps/faulhaber.md
 */

#pragma once
#include <vector>
#include "../modint.hpp"
#include "../lagrange_interpolation2.hpp"

template <int T>
MInt<T> faulhaber(long long n, int k) {
  using ModInt = MInt<T>;
  if (n < 1) return 0;
  std::vector<ModInt> y(k + 2, 0);
  for (int i = 1; i < k + 2; ++i) y[i] = y[i - 1] + ModInt(i).pow(k);
  return n - 1 < k + 2 ? y[n - 1] : lagrange_interpolation(y, ModInt(n - 1));
}
