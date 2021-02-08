/**
 * @brief Prim 法 重量版
 * @docs docs/graph/mst/mst.md
 */

#pragma once
#include <functional>
#include <queue>
#include <vector>
#include "../edge.hpp"

template <typename CostType>
std::vector<Edge<CostType>> prim(const std::vector<std::vector<Edge<CostType>>> &graph, int root = 0) {
  int n = graph.size();
  std::vector<Edge<CostType>> res;
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
    res.emplace_back(now);
    for (const Edge<CostType> &e : graph[now.dst]) {
      if (!visited[e.dst]) que.emplace(e);
    }
  }
  return res;
}
