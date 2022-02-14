#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

#include "../data_structure/fenwick_tree/fenwick_tree.hpp"

template <typename T>
long long inversion_number(const std::vector<T>& a) {
  const int n = a.size();
  std::vector<T> b = a;
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  FenwickTree<int> bit(b.size());
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    const int idx = std::distance(
        b.begin(), std::lower_bound(b.begin(), b.end(), a[i]));
    res += i - bit.sum(idx + 1);
    bit.add(idx, 1);
  }
  return res;
}
