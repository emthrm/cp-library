/**
 * @brief 最長増加部分列 RMQ 版
 * @docs docs/dp/lis/lis.md
 */

#pragma once
#include <algorithm>
#include <limits>
#include <vector>
#include "../../data_structure/segment_tree/segment_tree.hpp"

template <typename T>
int lis_rmq(const std::vector<T> &a, const T TINF) {
  int n = a.size();
  std::vector<T> b(a);
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  static T tinf = TINF;
  struct Node {
    using Monoid = T;
    static constexpr T unity() { return tinf; }
    static T merge(const T &a, const T &b) { return std::min(a, b); }
  };
  SegmentTree<Node> rmq(b.size() + 1);
  rmq.set(0, 0);
  for (int i = 0; i < n; ++i) {
    int idx = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    rmq.set(idx, rmq.get(0, idx) - 1);
  }
  return -rmq.get(0, b.size() + 1);
}
