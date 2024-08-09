/*
 * @title データ構造/双対セグメント木
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/range_affine_point_get
 */

#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/data_structure/dual_segment_tree.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n, q;
  std::cin >> n >> q;
  std::vector<ModInt> a(n);
  for (ModInt& a_i : a) std::cin >> a_i;
  struct M {
    using Elem = ModInt;
    using OperatorMonoid = std::pair<ModInt, ModInt>;
    static OperatorMonoid id() { return {ModInt::raw(1), ModInt::raw(0)}; }
    static OperatorMonoid merge(const OperatorMonoid& a,
                                const OperatorMonoid& b) {
      return {a.first * b.first, a.second * b.first + b.second};
    }
    static Elem apply(const Elem& a, const OperatorMonoid& b) {
      return a * b.first + b.second;
    }
  };
  emthrm::DualSegmentTree<M> dst(a);
  while (q--) {
    int type;
    std::cin >> type;
    if (type == 0) {
      int l, r;
      ModInt b, c;
      std::cin >> l >> r >> b >> c;
      dst.apply(l, r, {b, c});
    } else if (type == 1) {
      int i;
      std::cin >> i;
      std::cout << dst[i] << '\n';
    }
  }
  return 0;
}
