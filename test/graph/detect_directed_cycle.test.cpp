/*
 * @brief グラフ/閉路の検出 有向グラフ版
 */
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>
#include <vector>

#include "../../graph/edge.hpp"
#include "../../graph/detect_directed_cycle.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph[u].emplace_back(u, v, i);
  }
  std::vector<int> e;
  for (const Edge<int>& edge : detect_directed_cycle(graph)) {
    e.emplace_back(edge.cost);
  }
  if (e.empty()) {
    std::cout << "-1\n";
  } else {
    std::cout << e.size() << '\n';
    for (const int ver : e) std::cout << ver << '\n';
  }
  return 0;
}
