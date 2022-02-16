#pragma once
#include <functional>
#include <vector>

bool is_bipartite(const std::vector<std::vector<int>>& graph,
                  std::vector<int>* color) {
  const int n = graph.size();
  color->assign(n, -1);
  const std::function<bool(int, int)> dfs = [&graph, &color, &dfs](
      const int ver, const int c) -> bool {
    (*color)[ver] = c;
    for (const int e : graph[ver]) {
      if ((*color)[e] == c || ((*color)[e] == -1 && !dfs(e, c ^ 1))) {
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
