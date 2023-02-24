/*
 * @title データ構造/遅延伝播セグメント木 (range sum query and range update query)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include <iostream>

#include "emthrm/data_structure/lazy_segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  emthrm::LazySegmentTree<emthrm::monoid::RangeSumAndUpdateQuery<long long>>
      rsq(emthrm::monoid::RangeSumAndUpdateQuery<long long>::init(n));
  while (q--) {
    int query, s, t;
    std::cin >> query >> s >> t;
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
