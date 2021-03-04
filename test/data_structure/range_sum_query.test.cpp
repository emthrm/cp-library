/*
 * @brief データ構造/セグメント木 (range sum query)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "../../data_structure/segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  SegmentTree<monoid::RangeSumQuery<long long>> seg(n);
  while (q--) {
    int com, x, y;
    std::cin >> com >> x >> y; --x;
    if (com == 0) {
      seg.set(x, seg[x] + y);
    } else {
      --y;
      std::cout << seg.get(x, y + 1) << '\n';
    }
  }
  return 0;
}
