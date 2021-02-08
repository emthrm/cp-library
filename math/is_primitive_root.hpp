/**
 * @brief 原始根判定
 * @docs docs/math/primitive_root.md
 */

#pragma once
#include <vector>
#include "divisor.hpp"
#include "mod_pow.hpp"

bool is_primitive_root(int primitive_root, int mod) {
  std::vector<int> d = divisor(mod - 1);
  d.pop_back();
  for (int e : d) {
    if (mod_pow(primitive_root, e, mod) == 1) return false;
  }
  return true;
}
