/**
 * @brief Eulerian number の数表 形式的冪級数版
 * @docs docs/math/fps/eulerian_number.md
 */

#pragma once
#include <cassert>
#include <vector>
#include "../modint.hpp"
#include "fps.hpp"

std::vector<ModInt> eulerian_number_init_with_fps(int n, const Combinatorics &com) {
  if (n == 0) return {1};
  assert(com.val >= n + 1);
  int sz = (n + 1) >> 1;
  FPS<ModInt> a(sz - 1), b(sz - 1);
  for (int i = 0; i < sz; ++i) a[i] = ModInt(i + 1).pow(n);
  for (int i = 0; i < sz; ++i) b[i] = com.fact_inv[i] * com.fact_inv[n + 1 - i] * (i & 1 ? -1 : 1);
  a *= b;
  a.co.resize(n + 1, 0);
  for (int i = 0; i < sz; ++i) {
    a.co[i] *= com.fact[n + 1];
    a.co[n - 1 - i] = a.co[i];
  }
  return a.co;
}
