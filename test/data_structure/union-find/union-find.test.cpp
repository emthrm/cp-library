/*
 * @brief データ構造/union-find/union-find
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <iostream>

#include "emthrm/data_structure/union-find/union-find.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  emthrm::UnionFind union_find(n);
  while (q--) {
    int com, x, y;
    std::cin >> com >> x >> y;
    if (com == 0) {
      union_find.unite(x, y);
    } else if (com == 1) {
      std::cout << union_find.is_same(x, y) << '\n';
    }
  }
  return 0;
}
