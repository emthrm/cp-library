#pragma once
#include <utility>
#include <vector>

template <typename T>
std::vector<std::pair<T, int>> prime_factorization(T val) {
  std::vector<std::pair<T, int>> res;
  for (T i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}
