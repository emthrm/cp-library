/**
 * @brief ファウルハーバーの公式 ラグランジュ補間版
 * @docs docs/math/formal_power_series/faulhaber.md
 */

#pragma once
#include <vector>

#include "emthrm/math/lagrange_interpolation2.hpp"
#include "emthrm/math/modint.hpp"

template <int T>
MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k) {
  using ModInt = MInt<T>;
  if (n < 1) return 0;
  std::vector<ModInt> y(k + 2, 0);
  for (int i = 1; i < k + 2; ++i) {
    y[i] = y[i - 1] + ModInt(i).pow(k);
  }
  return n - 1 < k + 2 ? y[n - 1] : lagrange_interpolation(y, ModInt(n - 1));
}
