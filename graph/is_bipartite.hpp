#pragma once
#include <functional>
#include <vector>
#include "edge.hpp"

template <typename CostType>
bool is_bipartite(const std::vector<std::vector<Edge<CostType>>> &graph, std::vector<int> &color) {
  int n = graph.size();
  color.assign(n, -1);
  std::function<bool(int, int)> dfs = [&graph, &color, &dfs](int ver, int now) -> bool {
    color[ver] = now;
    for (const Edge<CostType> &e : graph[ver]) {
      if (color[e.dst] == now || (color[e.dst] == -1 && !dfs(e.dst, now ^ 1))) return false;
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1 && !dfs(i, 0)) return false;
  }
  return true;
}
