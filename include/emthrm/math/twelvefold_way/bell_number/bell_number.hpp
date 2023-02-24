/**
 * @title ベル数
 * @docs docs/math/twelvefold_way/bell_number/bell_number.md
 */

#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_HPP_
#define EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_HPP_

#include <cassert>
#include <numeric>
#include <vector>

#include "emthrm/math/modint.hpp"

namespace emthrm {

template <int T>
MInt<T> bell_number(const int n, int k) {
  using ModInt = MInt<T>;
  if (k > n) k = n;
  ModInt::init(k);
  std::vector<ModInt> tmp(k + 1);
  for (int i = 0; i <= k; ++i) {
    tmp[i] = (i & 1 ? -ModInt::fact_inv(i) : ModInt::fact_inv(i));
  }
  std::partial_sum(tmp.begin(), tmp.end(), tmp.begin());
  ModInt bell = 0;
  for (int i = 0; i <= k; ++i) {
    bell += ModInt(i).pow(n) * ModInt::fact_inv(i) * tmp[k - i];
  }
  return bell;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_BELL_NUMBER_BELL_NUMBER_HPP_
