/*
 * @title データ構造/遅延伝播セグメント木 (range minimum query and range add query)
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_add_range_min
 */

#include <iostream>
#include <limits>

#include "emthrm/data_structure/lazy_segment_tree.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  emthrm::LazySegmentTree<emthrm::monoid::RangeMinimumAndAddQuery<
      int64_t, std::numeric_limits<int64_t>::max()>> a(n);
  for (int i = 0; i < n; ++i) {
    int a_i;
    std::cin >> a_i;
    a.set(i, a_i);
  }
  while (q--) {
    int type, l, r;
    std::cin >> type >> l >> r;
    if (type == 0) {
      int x;
      std::cin >> x;
      a.apply(l, r, x);
    } else if (type == 1) {
      std::cout << a.get(l, r) << '\n';
    }
  }
  return 0;
}
