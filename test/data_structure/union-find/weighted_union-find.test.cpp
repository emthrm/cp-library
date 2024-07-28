/*
 * @title データ構造/素集合データ構造/重みつき union-find
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind_with_potential
 */

#include <cassert>
#include <iostream>

#include "emthrm/data_structure/union-find/weighted_union-find.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  constexpr int MOD = 998244353;
  using ModInt = emthrm::MInt<MOD>;
  int n, q;
  std::cin >> n >> q;
  emthrm::WeightedUnionFind<ModInt> union_find(n);
  while (q--) {
    int t, u, v;
    std::cin >> t >> u >> v;
    if (t == 0) {
      int x;
      std::cin >> x;
      if (union_find.is_same(u, v)) {
        std::cout << (union_find.diff(v, u) == x) << '\n';
      } else {
        assert(union_find.unite(v, u, x));
        std::cout << "1\n";
      }
    } else if (t == 1) {
      if (union_find.is_same(u, v)) {
        std::cout << union_find.diff(v, u) << '\n';
      } else {
        std::cout << "-1\n";
      }
    }
  }
  return 0;
}
