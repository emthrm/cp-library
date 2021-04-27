/*
 * @brief データ構造/union-find/部分永続 union-find
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h"

#include <iostream>
#include "../../../data_structure/union-find/partially_persistent_union-find.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  PartiallyPersistentUnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    uf.unite(i, a, b);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    if (!uf.same(m - 1, x, y)) {
      std::cout << "-1\n";
      continue;
    }
    int lb = -1, ub = m - 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      (uf.same(mid, x, y) ? ub : lb) = mid;
    }
    std::cout << ub + 1 << '\n';
  }
  return 0;
}
