/**
 * @brief ベル数
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#pragma once
#include <cassert>
#include <vector>
#include "../../modint.hpp"

ModInt bell_number(int n, int k, const Combinatorics &com) {
  if (k > n) k = n;
  assert(k <= com.val);
  std::vector<ModInt> cumulative(k + 1);
  for (int i = 0; i <= k; ++i) cumulative[i] = com.fact_inv[i] * (i & 1 ? -1 : 1);
  for (int i = 0; i < k; ++i) cumulative[i + 1] += cumulative[i];
  ModInt bell = 0;
  for (int i = 0; i <= k; ++i) bell += ModInt(i).pow(n) * com.fact_inv[i] * cumulative[k - i];
  return bell;
}
