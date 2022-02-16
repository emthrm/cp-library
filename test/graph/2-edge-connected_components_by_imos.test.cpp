/*
 * @brief グラフ/二重辺連結成分分解 いもす法版
 */
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include <vector>

#include "../../graph/2-edge-connected_components_by_imos.hpp"
#include "../../graph/edge.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<bool>>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(a, b);
    graph[b].emplace_back(b, a);
  }
  const std::vector<std::vector<int>> ans =
      TwoEdgeConnectedComponentsByImos<bool>(graph, true).vertices;
  const int k = ans.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    const int l = ans[i].size();
    std::cout << l << ' ';
    for (int j = 0; j < l; ++j) {
      std::cout << ans[i][j] << " \n"[j + 1 == l];
    }
  }
  return 0;
}