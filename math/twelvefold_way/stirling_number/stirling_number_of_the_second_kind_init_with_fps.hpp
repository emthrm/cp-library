/**
 * @brief 第2種スターリング数の数表 形式的冪級数版
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.md
 */

#pragma once
#include <vector>
#include "../../modint.hpp"
#include "../../fps/fps.hpp"

std::vector<ModInt> stirling_number_of_the_second_kind_init_with_fps(int n, const Combinatorics &com) {
  assert(com.val >= n);
  FPS<ModInt> a(n), b(n);
  for (int i = 0; i <= n; ++i) a[i] = ModInt(i).pow(n) * com.fact_inv[i];
  for (int i = 0; i <= n; ++i) b[i] = com.fact_inv[i] * (i & 1 ? -1 : 1);
  a *= b;
  a.co.resize(n + 1);
  return a.co;
}
