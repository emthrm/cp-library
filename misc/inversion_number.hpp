#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include "../data_structure/fenwick_tree/fenwick_tree.hpp"

template <typename T>
long long inversion_number(const std::vector<T> &a) {
  int n = a.size();
  std::vector<T> comp(a);
  std::sort(comp.begin(), comp.end());
  comp.erase(std::unique(comp.begin(), comp.end()), comp.end());
  FenwickTree<int> bit(comp.size());
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int idx = std::distance(comp.begin(), std::lower_bound(comp.begin(), comp.end(), a[i]));
    res += i - bit.sum(idx + 1);
    bit.add(idx, 1);
  }
  return res;
}
