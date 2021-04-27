/*
 * @brief データ構造/union-find/union-find
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <iostream>
#include "../../../data_structure/union-find/union-find.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  UnionFind uf(n);
  while (q--) {
    int com, x, y;
    std::cin >> com >> x >> y;
    if (com == 0) {
      uf.unite(x, y);
    } else if (com == 1) {
      std::cout << uf.same(x, y) << '\n';
    }
  }
  return 0;
}
