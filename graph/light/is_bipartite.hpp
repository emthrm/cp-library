#pragma once
#include <functional>
#include <vector>

bool is_bipartite(const std::vector<std::vector<int>> &graph, std::vector<int> &color) {
  int n = graph.size();
  color.assign(n, 0);
  std::function<bool(int, int)> dfs = [&graph, &color, &dfs](int ver, int now) -> bool {
    color[ver] = now;
    for (int e : graph[ver]) {
      if (color[e] == now || (color[e] == 0 && !dfs(e, -now))) return false;
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (color[i] == 0 && !dfs(i, 1)) return false;
  }
  return true;
}
