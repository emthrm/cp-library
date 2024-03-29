/*
 * @title データ構造/セグメント木
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite
 */

#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/data_structure/segment_tree.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n, q;
  std::cin >> n >> q;
  struct M {
    using Monoid = std::pair<ModInt, ModInt>;
    static constexpr Monoid id() { return {1, 0}; }
    static Monoid merge(const Monoid& a, const Monoid& b) {
      return {a.first * b.first, a.second * b.first + b.second};
    }
  };
  std::vector<M::Monoid> f(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> f[i].first >> f[i].second;
  }
  emthrm::SegmentTree<M> seg(f);
  while (q--) {
    int query;
    std::cin >> query;
    if (query == 0) {
      int p, c, d;
      std::cin >> p >> c >> d;
      seg.set(p, {c, d});
    } else if (query == 1) {
      int l, r, x;
      std::cin >> l >> r >> x;
      const M::Monoid ans = seg.get(l, r);
      std::cout << ans.first * x + ans.second << '\n';
    }
  }
  return 0;
}
