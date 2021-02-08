/**
 * @brief 閉路の検出 有向グラフ版
 * @docs docs/graph/detect_cycle.md
 */

#pragma once
#include <algorithm>
#include <functional>
#include <vector>
#include "edge.hpp"

template <typename CostType>
std::vector<Edge<CostType>> detect_directed_cycle(const std::vector<std::vector<Edge<CostType>>> &graph) {
  int n = graph.size();
  std::vector<int> visited(n, 0);
  std::vector<Edge<CostType>> edges, cycle;
  std::function<bool(int)> dfs = [&graph, &visited, &edges, &cycle, &dfs](int ver) -> bool {
    visited[ver] = 1;
    for (const Edge<CostType> &e : graph[ver]) {
      if (visited[e.dst] == 1) {
        cycle.emplace_back(e);
        while (edges.back().src != e.dst) {
          cycle.emplace_back(edges.back());
          edges.pop_back();
        }
        cycle.emplace_back(edges.back());
        std::reverse(cycle.begin(), cycle.end());
        return true;
      } else if (visited[e.dst] == 0) {
        edges.emplace_back(e);
        if (dfs(e.dst)) return true;
        edges.pop_back();
      }
    }
    visited[ver] = 2;
    return false;
  };
  for (int i = 0; i < n; ++i) {
    if (visited[i] == 0 && dfs(i)) return cycle;
  }
  return cycle;
}
