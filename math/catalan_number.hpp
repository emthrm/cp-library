#pragma once
#include <vector>

#include "./modint.hpp"

template <int T>
std::vector<MInt<T>> catalan_number(const int n) {
  using ModInt = MInt<T>;
  ModInt::inv(n + 1, true);
  std::vector<ModInt> c(n + 1);
  c[0] = 1;
  for (int i = 0; i < n; ++i) {
    c[i + 1] = c[i] * ModInt::inv(i + 2) * 2 * (2 * i + 1);
  }
  return c;
}
