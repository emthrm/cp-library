/*
 * @brief データ構造/union-find/undo 可能 union-find
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e"

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "../../../data_structure/union-find/undoable_union-find.hpp"

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> u(m), v(m), s(n);
  for (int i = 0; i < m; ++i) {
    std::cin >> u[i] >> v[i];
    --u[i]; --v[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
    --s[i];
  }
  UndoableUnionFind union_find(n);
  std::map<std::pair<int, int>, std::vector<int>> edges;
  for (int i = 0; i < m; ++i) {
    if (s[u[i]] == s[v[i]]) {
      union_find.unite(u[i], v[i]);
    } else {
      edges[std::minmax(s[u[i]], s[v[i]])].emplace_back(i);
    }
  }
  union_find.snapshot();
  int q;
  std::cin >> q;
  std::map<std::pair<int, int>, std::vector<int>> queries;
  std::vector<int> a(q), b(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> a[i] >> b[i];
    --a[i]; --b[i];
    queries[std::minmax(s[a[i]], s[b[i]])].emplace_back(i);
  }
  std::vector<int> ans(q);
  for (const auto& sasb_query : queries) {
    if (edges.count(sasb_query.first)) {
      for (const int id : edges[sasb_query.first]) {
        union_find.unite(u[id], v[id]);
      }
    }
    for (const int id : sasb_query.second) {
      ans[id] = union_find.is_same(a[id], b[id]);
    }
    union_find.rollback();
  }
  for (int i = 0; i < q; ++i) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}
