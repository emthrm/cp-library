/*
 * @brief グラフ/二重辺連結成分分解 いもす法版
 */
#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../graph/2-edge-connected_components_imos.hpp"

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
  TwoEdgeConnectedComponentsImos<bool> tecc(graph, true);
  int k = tecc.vertices.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    int l = tecc.vertices[i].size();
    std::cout << l << ' ';
    for (int j = 0; j < l; ++j) std::cout << tecc.vertices[i][j] << " \n"[j + 1 == l];
  }
  return 0;
}
