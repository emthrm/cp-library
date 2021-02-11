#pragma once
#include <cassert>
#include <vector>
#include "modint.hpp"

std::vector<ModInt> catalan_number(int n, const Combinatorics &com) {
  assert(n + 1 <= com.val);
  std::vector<ModInt> catalan(n + 1);
  catalan[0] = 1;
  for (int i = 0; i < n; ++i) catalan[i + 1] = catalan[i] * com.inv[i + 2] * 2 * (2 * i + 1);
  return catalan;
}
