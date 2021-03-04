/*
 * @brief データ構造/セグメント木 (range minimum query)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <iostream>
#include "../../data_structure/segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  SegmentTree<monoid::RangeMinimumQuery<int>> seg(n);
  while (q--) {
    int com, x, y;
    std::cin >> com >> x >> y;
    if (com == 0) {
      seg.set(x, y);
    } else if (com == 1) {
      std::cout << seg.get(x, y + 1) << '\n';
    }
  }
  return 0;
}
