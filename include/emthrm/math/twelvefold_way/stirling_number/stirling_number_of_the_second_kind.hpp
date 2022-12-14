/**
 * @brief 第2種スターリング数
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md
 */

#pragma once
#include <cassert>

#include "emthrm/math/modint.hpp"

template <int T>
MInt<T> stirling_number_of_the_second_kind(const int n, const int k) {
  using ModInt = MInt<T>;
  if (n < k) return 0;
  ModInt::init(k);
  ModInt s = 0;
  for (int i = 1; i <= k; ++i) {
    s += ModInt::nCk(k, i)
         * ((k - i) & 1 ? -ModInt(i).pow(n) : ModInt(i).pow(n));
  }
  return s * ModInt::fact_inv(k);
}
