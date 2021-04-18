/*
 * @brief グラフ/強連結成分分解
 */
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../graph/strongly_connected_components.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<bool>>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(a, b);
  }
  StronglyConnectedComponents<bool> scc(graph, true);
  int k = scc.vertices.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    int l = scc.vertices[i].size();
    std::cout << l << ' ';
    for (int j = 0; j < l; ++j) std::cout << scc.vertices[i][j] << " \n"[j + 1 == l];
  }
  return 0;
}
