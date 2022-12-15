/*
 * @brief データ構造/union-find/部分永続 union-find
 */
#define PROBLEM "https://atcoder.jp/contests/agc002/tasks/agc002_d"

#include <iostream>

#include "emthrm/data_structure/union-find/partially_persistent_union-find.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  emthrm::PartiallyPersistentUnionFind union_find(n);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    union_find.unite(i, a, b);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    --x; --y;
    int lb = 0, ub = m;
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      (union_find.size(mid, x) + (union_find.is_same(mid, x, y) ?
       0 : union_find.size(mid, y)) >= z ? ub : lb) = mid;
    }
    std::cout << lb + 1 << '\n';
  }
  return 0;
}
