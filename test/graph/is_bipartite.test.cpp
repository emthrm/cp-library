/*
 * @brief グラフ/二部グラフ判定
 */
#define PROBLEM "https://atcoder.jp/contests/arc099/tasks/arc099_c"

#include <iostream>
#include <map>
#include <tuple>
#include <utility>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../data_structure/union-find/union-find.hpp"
#include "../../graph/is_bipartite.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  int ans = m;
  std::vector<std::vector<int>> adj(n, std::vector<int>(n, false));
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    adj[a][b] = adj[b][a] = true;
  }
  UnionFind uf(n);
  std::vector<std::vector<Edge<bool>>> graph(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (!adj[i][j]) {
        uf.unite(i, j);
        graph[i].emplace_back(i, j);
        graph[j].emplace_back(j, i);
      }
    }
  }
  std::vector<int> color;
  if (!is_bipartite(graph, color)) {
    std::cout << "-1\n";
    return 0;
  }
  std::vector<int> dp(n + 1, false);
  dp[0] = true;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[uf.root(i)] += color[i];
  }
  for (const std::pair<int, int> &p : mp) {
    int root, size;
    std::tie(root, size) = p;
    for (int i = n; i >= 0; --i) {
      if (dp[i]) {
        dp[i] = false;
        if (i + size <= n) dp[i + size] = true;
        if (i + uf.size(root) - size <= n) dp[i + uf.size(root) - size] = true;
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (dp[i]) {
      const int edge = i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2;
      if (edge < ans) {
        ans = edge;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}
