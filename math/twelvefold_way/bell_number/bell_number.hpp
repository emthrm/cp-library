/**
 * @brief ベル数
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#pragma once
#include <cassert>
#include <vector>
#include "../../modint.hpp"

template <int T>
MInt<T> bell_number(const int n, int k) {
  using ModInt = MInt<T>;
  if (k > n) k = n;
  ModInt::init(k);
  std::vector<ModInt> tmp(k + 1);
  for (int i = 0; i <= k; ++i) {
    tmp[i] = ModInt::fact_inv(i) * (i & 1 ? -1 : 1);
  }
  for (int i = 0; i < k; ++i) {
    tmp[i + 1] += tmp[i];
  }
  ModInt bell = 0;
  for (int i = 0; i <= k; ++i) {
    bell += ModInt(i).pow(n) * ModInt::fact_inv(i) * tmp[k - i];
  }
  return bell;
}
