/**
 * @brief 第2種スターリング数
 * @docs docs/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.md
 */

#pragma once
#include <cassert>
#include "../../modint.hpp"

template <int T>
MInt<T> stirling_number_of_the_second_kind(int n, int k) {
  using ModInt = MInt<T>;
  if (n < k) return 0;
  ModInt::init(k);
  ModInt stirling = 0;
  for (int i = 1; i <= k; ++i) {
    ModInt tmp = ModInt::nCk(k, i) * ModInt(i).pow(n);
    if ((k - i) & 1) {
      stirling -= tmp;
    } else {
      stirling += tmp;
    }
  }
  return stirling * ModInt::fact_inv(k);
}
