#pragma once
#include <functional>
#include <vector>

#include "./edge.hpp"

template <typename CostType>
bool is_bipartite(const std::vector<std::vector<Edge<CostType>>>& graph,
                  std::vector<int>* color) {
  const int n = graph.size();
  color->assign(n, -1);
  const std::function<bool(int, int)> dfs = [&graph, &color, &dfs](
      const int ver, const int c) -> bool {
    (*color)[ver] = c;
    for (const Edge<CostType>& e : graph[ver]) {
      if ((*color)[e.dst] == c ||
          ((*color)[e.dst] == -1 && !dfs(e.dst, c ^ 1))) {
        return false;
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if ((*color)[i] == -1 && !dfs(i, 0)) {
      color->clear();
      return false;
    }
  }
  return true;
}
