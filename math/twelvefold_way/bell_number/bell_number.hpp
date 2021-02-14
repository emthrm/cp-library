/**
 * @brief ベル数
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#pragma once
#include <cassert>
#include <vector>
#include "../../modint.hpp"

template <int T>
MInt<T> bell_number(int n, int k) {
  using ModInt = MInt<T>;
  if (k > n) k = n;
  ModInt::init(k);
  std::vector<ModInt> cumulative(k + 1);
  for (int i = 0; i <= k; ++i) cumulative[i] = ModInt::fact_inv(i) * (i & 1 ? -1 : 1);
  for (int i = 0; i < k; ++i) cumulative[i + 1] += cumulative[i];
  ModInt bell = 0;
  for (int i = 0; i <= k; ++i) bell += ModInt(i).pow(n) * ModInt::fact_inv(i) * cumulative[k - i];
  return bell;
}
