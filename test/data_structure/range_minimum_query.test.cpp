/*
 * @title データ構造/セグメント木 (range minimum query)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include <iostream>

#include "emthrm/data_structure/segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  emthrm::SegmentTree<emthrm::monoid::RangeMinimumQuery<int>> rmq(n);
  while (q--) {
    int com, x, y;
    std::cin >> com >> x >> y;
    if (com == 0) {
      rmq.set(x, y);
    } else if (com == 1) {
      std::cout << rmq.get(x, y + 1) << '\n';
    }
  }
  return 0;
}
