/*
 * @brief データ構造/遅延伝播セグメント木 (range sum query and range add query)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <iostream>

#include "../../data_structure/lazy_segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  LazySegmentTree<monoid::RangeSumAndAddQuery<long long>>
      rsq(monoid::RangeSumAndAddQuery<long long>::init(n));
  while (q--) {
    int query, s, t;
    std::cin >> query >> s >> t; --s; --t;
    if (query == 0) {
      int x;
      std::cin >> x;
      rsq.apply(s, t + 1, x);
    } else if (query == 1) {
      std::cout << rsq.get(s, t + 1).sum << '\n';
    }
  }
  return 0;
}
