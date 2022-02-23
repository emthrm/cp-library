/**
 * @brief 有向閉路の検出
 * @docs docs/graph/detect_walk.md
 */

#pragma once
#include <algorithm>
#include <functional>
#include <vector>

#include "./edge.hpp"

template <typename CostType>
std::vector<Edge<CostType>> detect_directed_cycle(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> is_visited(n, 0);
  std::vector<Edge<CostType>> edges, cycle;
  const std::function<bool(int)> dfs =
      [&graph, &is_visited, &edges, &cycle, &dfs](const int ver) -> bool {
        is_visited[ver] = 1;
        for (const Edge<CostType>& e : graph[ver]) {
          if (is_visited[e.dst] == 1) {
            cycle.emplace_back(e);
            while (cycle.back().src != e.dst) {
              cycle.emplace_back(edges.back());
              edges.pop_back();
            }
            std::reverse(cycle.begin(), cycle.end());
            return true;
          } else if (is_visited[e.dst] == 0) {
            edges.emplace_back(e);
            if (dfs(e.dst)) return true;
            edges.pop_back();
          }
        }
        is_visited[ver] = 2;
        return false;
      };
  for (int i = 0; i < n; ++i) {
    if (is_visited[i] == 0 && dfs(i)) break;
  }
  return cycle;
}
