/*
 * @brief データ構造/union-find/undo 可能 union-find
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/contest/1444/problem/C"

#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <utility>
#include <vector>
#include "../../../data_structure/union-find/undoable_union-find.hpp"

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
    --c[i];
  }
  UndoableUnionFind union_find(n * 2);
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> edge;
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    if (c[a] == c[b]) {
      union_find.unite(a, b + n);
      union_find.unite(b, a + n);
    } else {
      if (c[a] > c[b]) {
        std::swap(a, b);
      }
      edge[{c[a], c[b]}].emplace_back(a, b);
    }
  }
  std::vector<int> is_bad(k, false);
  for (int i = 0; i < n; ++i) {
    if (union_find.is_same(i, i + n)) {
      is_bad[c[i]] = true;
    }
  }
  const int good_group_num = std::count(is_bad.begin(), is_bad.end(), false);
  long long ans = static_cast<long long>(good_group_num) * (good_group_num - 1) / 2;
  union_find.snapshot();
  for (const std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>> &p : edge) {
    if (is_bad[p.first.first] || is_bad[p.first.second]) continue;
    bool is_bad = false;
    for (const std::pair<int, int> &e : p.second) {
      int a, b;
      std::tie(a, b) = e;
      union_find.unite(a, b + n);
      union_find.unite(b, a + n);
      is_bad |= union_find.is_same(a, a + n) || union_find.is_same(b, b + n);
    }
    union_find.rollback();
    ans -= is_bad;
  }
  std::cout << ans << '\n';
  return 0;
}
