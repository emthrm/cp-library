#pragma once
#include "../modint.hpp"

template <int P>
MInt<P> lucas(int n, int k) {
  using ModInt = MInt<P>;
  if (n < 0 || n < k || k < 0) return 0;
  ModInt::init(P - 1);
  ModInt binom = 1;
  for (; n > 0 || k > 0; n /= P, k /= P) {
    binom *= ModInt::nCk(n % P, k % P);
  }
  return binom;
}
