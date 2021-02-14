#pragma once
#include <vector>
#include "modint.hpp"

template <int T>
std::vector<MInt<T>> catalan_number(int n) {
  using ModInt = MInt<T>;
  ModInt::inv(n + 1, true);
  std::vector<ModInt> catalan(n + 1);
  catalan[0] = 1;
  for (int i = 0; i < n; ++i) catalan[i + 1] = catalan[i] * ModInt::inv(i + 2) * 2 * (2 * i + 1);
  return catalan;
}
