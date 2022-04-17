/*
 * @brief データ構造/セグメント木
 */
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <utility>
#include <vector>

#include "../../data_structure/segment_tree.hpp"
#include "../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  int n, q;
  std::cin >> n >> q;
  struct M {
    using Monoid = std::pair<ModInt, ModInt>;
    static Monoid id() { return {1, 0}; }
    static Monoid merge(const Monoid& a, const Monoid& b) {
      return {a.first * b.first, a.second * b.first + b.second};
    }
  };
  std::vector<M::Monoid> f(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> f[i].first >> f[i].second;
  }
  SegmentTree<M> seg(f);
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
