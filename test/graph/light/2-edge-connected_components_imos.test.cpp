#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include <iostream>
#include <vector>
#include "../../../graph/light/2-edge-connected_components_imos.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  TwoEdgeConnectedComponentsImos tecc(graph, true);
  int k = tecc.vertices.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    int l = tecc.vertices[i].size();
    std::cout << l << ' ';
    for (int j = 0; j < l; ++j) std::cout << tecc.vertices[i][j] << " \n"[j + 1 == l];
  }
  return 0;
}
