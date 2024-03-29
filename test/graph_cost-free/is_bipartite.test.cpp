/*
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/arc099/tasks/arc099_c
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "emthrm/data_structure/union-find/union-find.hpp"
#include "emthrm/graph_cost-free/is_bipartite.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  int ans = m;
  std::vector<std::vector<bool>> is_adjacent(n, std::vector<bool>(n, false));
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    is_adjacent[a][b] = true;
    is_adjacent[b][a] = true;
  }
  emthrm::UnionFind union_find(n);
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (!is_adjacent[i][j]) {
        union_find.unite(i, j);
        graph[i].emplace_back(j);
        graph[j].emplace_back(i);
      }
    }
  }
  const std::vector<int> color = emthrm::is_bipartite(graph);
  if (color.empty()) {
    std::cout << "-1\n";
    return 0;
  }
  std::vector<bool> dp(n + 1, false);
  dp[0] = true;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[union_find.root(i)] += color[i];
  }
  for (const auto& [root, size] : mp) {
    for (int i = n; i >= 0; --i) {
      if (dp[i]) {
        dp[i] = false;
        if (i + size <= n) dp[i + size] = true;
        if (i + union_find.size(root) - size <= n) {
          dp[i + union_find.size(root) - size] = true;
        }
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (dp[i]) ans = std::min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
  }
  std::cout << ans << '\n';
  return 0;
}
