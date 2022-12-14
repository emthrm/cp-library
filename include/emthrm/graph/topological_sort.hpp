#pragma once
#include <queue>
#include <vector>

#include "./edge.hpp"

template <typename CostType>
std::vector<int> topological_sort(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (const Edge<CostType>& e : graph[i]) ++deg[e.dst];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  res.reserve(n);
  while (!que.empty()) {
    const int ver = que.front();
    que.pop();
    res.emplace_back(ver);
    for (const Edge<CostType>& e : graph[ver]) {
      if (--deg[e.dst] == 0) que.emplace(e.dst);
    }
  }
  return res.size() == n ? res : std::vector<int>{};
}
