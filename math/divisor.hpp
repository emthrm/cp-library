#pragma once
#include <algorithm>
#include <vector>

template <typename T>
std::vector<T> divisor(T val) {
  std::vector<T> res;
  for (T i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}
