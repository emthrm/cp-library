/*
 * @brief データ構造/union-find 木/重みつき union-find 木
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <iostream>
#include "../../../data_structure/union-find/weighted_union-find.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  WeightedUnionFind<int> uf(n);
  while (q--) {
    int query;
    std::cin >> query;
    if (query == 0) {
      int x, y, z;
      std::cin >> x >> y >> z;
      uf.unite(x, y, z);
    } else if (query == 1) {
      int x, y;
      std::cin >> x >> y;
      if (uf.same(x, y)) {
        std::cout << uf.diff(x, y) << '\n';
      } else {
        std::cout << "?\n";
      }
    }
  }
  return 0;
}
