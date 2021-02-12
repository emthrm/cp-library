/**
 * @brief 最長増加部分列 RMQ 版
 * @docs docs/dp/lis/lis.md
 */

#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include "../../data_structure/segment_tree/segment_tree.hpp"

template <typename T>
int lis_rmq(const std::vector<T> &a, bool is_strict = true) {
  int n = a.size();
  std::vector<T> b(a);
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  SegmentTree<monoid::RangeMaximumQuery<int>> rmq(b.size() + 1);
  rmq.set(0, 0);
  for (int i = 0; i < n; ++i) {
    int idx = std::distance(b.begin(), std::lower_bound(b.begin(), b.end(), a[i])) + 1;
    rmq.set(idx, rmq.get(0, is_strict ? idx : idx + 1) + 1);
  }
  return rmq.get(0, b.size() + 1);
}
