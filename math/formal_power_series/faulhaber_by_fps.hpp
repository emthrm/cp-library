/**
 * @brief ファウルハーバーの公式 形式的冪級数版
 * @docs docs/math/formal_power_series/faulhaber.md
 */

#pragma once
#include <cassert>
#include "../modint.hpp"
#include "bernoulli_number.hpp"

template <int T>
MInt<T> faulhaber_by_fps(long long n, int k) {
  using ModInt = MInt<T>;
  if (n <= 1) return 0;
  if (k == 0) return n - 1;
  ModInt::init(k + 1);
  std::vector<ModInt> bernoulli = bernoulli_number<ModInt>(k);
  ModInt p = 1, res = 0;
  for (int i = k; i >= 0; --i) {
    p *= n;
    res += ModInt::nCk(k + 1, i) * bernoulli[i] * p;
  }
  return res / (k + 1);
}
