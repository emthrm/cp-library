/*
 * @title グラフ/有向閉路の検出
 */
#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>
#include <ranges>
#include <vector>

#include "emthrm/graph/detect_directed_cycle.hpp"
#include "emthrm/graph/edge.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<emthrm::Edge<int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph[u].emplace_back(u, v, i);
  }
  // GCC 12 adopted P2415.
  const std::vector<emthrm::Edge<int>> cycle =
      emthrm::detect_directed_cycle(graph);
  const auto ev = cycle | std::views::transform(&emthrm::Edge<int>::cost);
  // const auto ev = emthrm::detect_directed_cycle(graph)
  //               | std::views::transform(&emthrm::Edge<int>::cost);
  const int l = ev.size();
  if (l == 0) {
    std::cout << "-1\n";
  } else {
    std::cout << l << '\n';
    for (const int e : ev) std::cout << e << '\n';
  }
  return 0;
}
