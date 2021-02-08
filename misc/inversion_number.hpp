#pragma once
#include <algorithm>
#include <vector>
#include "../data_structure/bit/bit.hpp"

template <typename T>
long long inversion_number(const std::vector<T> &a) {
  int n = a.size();
  std::vector<T> comp(a);
  std::sort(comp.begin(), comp.end());
  comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
  BIT<int> bit(comp.size());
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int idx = std::lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    res += i - bit.sum(idx + 1);
    bit.add(idx, 1);
  }
  return res;
}
