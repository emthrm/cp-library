/*
 * @title データ構造/union-find/重みつき union-find
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <iostream>

#include "emthrm/data_structure/union-find/weighted_union-find.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  emthrm::WeightedUnionFind<int> union_find(n);
  while (q--) {
    int query;
    std::cin >> query;
    if (query == 0) {
      int x, y, z;
      std::cin >> x >> y >> z;
      union_find.unite(x, y, z);
    } else if (query == 1) {
      int x, y;
      std::cin >> x >> y;
      if (union_find.is_same(x, y)) {
        std::cout << union_find.diff(x, y) << '\n';
      } else {
        std::cout << "?\n";
      }
    }
  }
  return 0;
}
