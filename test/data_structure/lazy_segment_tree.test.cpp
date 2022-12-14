/*
 * @brief データ構造/遅延伝播セグメント木
 */
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/data_structure/lazy_segment_tree.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  int n, q;
  std::cin >> n >> q;
  struct M {
    using Monoid = std::pair<ModInt, int>;
    using OperatorMonoid = std::pair<ModInt, ModInt>;
    static Monoid m_id() { return {0, 0}; }
    static OperatorMonoid o_id() { return {1, 0}; }
    static Monoid m_merge(const Monoid& a, const Monoid& b) {
      return {a.first + b.first, a.second + b.second};
    }
    static OperatorMonoid o_merge(const OperatorMonoid& a,
                                  const OperatorMonoid& b) {
      return {b.first * a.first, b.first * a.second + b.second};
    }
    static Monoid apply(const Monoid& a, const OperatorMonoid& b) {
      return {a.first * b.first + b.second * a.second, a.second};
    }
  };
  std::vector<M::Monoid> a(n, {0, 1});
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i].first;
  }
  LazySegmentTree<M> seg(a);
  while (q--) {
    int query, l, r;
    std::cin >> query >> l >> r;
    if (query == 0) {
      int b, c;
      std::cin >> b >> c;
      seg.apply(l, r, {b, c});
    } else if (query == 1) {
      std::cout << seg.get(l, r).first << '\n';
    }
  }
  return 0;
}
