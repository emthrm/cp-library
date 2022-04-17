/*
 * @brief データ構造/遅延伝播セグメント木 (range minimum query and range update query)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <iostream>

#include "../../data_structure/lazy_segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  LazySegmentTree<monoid::RangeMinimumAndUpdateQuery<int>> rmq(n);
  while (q--) {
    int query, s, t;
    std::cin >> query >> s >> t;
    if (query == 0) {
      int x;
      std::cin >> x;
      rmq.apply(s, t + 1, x);
    } else if (query == 1) {
      std::cout << rmq.get(s, t + 1) << '\n';
    }
  }
  return 0;
}
