/**
 * @brief Prim 法
 * @docs docs/graph/minimum_spanning_tree.md
 */

#pragma once
#include <functional>
#include <queue>
#include <vector>
#include "edge.hpp"

template <typename CostType>
CostType prim(const std::vector<std::vector<Edge<CostType>>> &graph, int root = 0) {
  int n = graph.size();
  CostType total = 0;
  std::vector<bool> visited(n, false);
  visited[root] = true;
  std::priority_queue<Edge<CostType>, std::vector<Edge<CostType>>, std::greater<Edge<CostType>>> que;
  for (const Edge<CostType> &e : graph[root]) {
    if (e.dst != root) que.emplace(e);
  }
  while (!que.empty()) {
    Edge<CostType> now = que.top(); que.pop();
    if (visited[now.dst]) continue;
    visited[now.dst] = true;
    total += now.cost;
    for (const Edge<CostType> &e : graph[now.dst]) {
      if (!visited[e.dst]) que.emplace(e);
    }
  }
  return total;
}
