/**
 * @brief 道の検出
 * @docs docs/graph/detect_walk.md
 */

#pragma once
#include <functional>
#include <vector>

#include "./edge.hpp"

template <typename CostType>
std::vector<Edge<CostType>> detect_path(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const int s, const int t) {
  std::vector<bool> is_visited(graph.size(), false);
  std::vector<Edge<CostType>> path;
  const std::function<bool(const int)> dfs =
      [&graph, t, &is_visited, &path, &dfs](const int ver) -> bool {
        if (ver == t) return true;
        is_visited[ver] = true;
        for (const Edge<CostType>& e : graph[ver]) {
          if (!is_visited[e.dst]) {
            path.emplace_back(e);
            if (dfs(e.dst)) return true;
            path.pop_back();
          }
        }
        return false;
      };
  dfs(s);
  return path;
}
