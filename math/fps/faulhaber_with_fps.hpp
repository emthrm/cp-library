/**
 * @brief ファウルハーバーの公式 形式的冪級数版
 * @docs docs/math/fps/faulhaber.md
 */

#pragma once
#include <cassert>
#include "../modint.hpp"
#include "bernoulli_number.hpp"

ModInt faulhaber(long long n, int k, const Combinatorics &com) {
  if (n <= 1) return 0;
  if (k == 0) return n - 1;
  assert(com.val >= k + 1);
  std::vector<ModInt> bernoulli = bernoulli_number<ModInt>(k);
  ModInt p = 1, res = 0;
  for (int i = k; i >= 0; --i) {
    p *= n;
    res += com.nCk(k + 1, i) * bernoulli[i] * p;
  }
  return res / (k + 1);
}
