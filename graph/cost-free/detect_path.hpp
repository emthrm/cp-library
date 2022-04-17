#pragma once
#include <functional>
#include <vector>

std::vector<int> detect_path(const std::vector<std::vector<int>>& graph,
                             const int s, const int t) {
  std::vector<bool> is_visited(graph.size(), false);
  std::vector<int> path{s};
  const std::function<bool(const int)> dfs =
      [&graph, t, &is_visited, &path, &dfs](const int ver) -> bool {
        if (ver == t) return true;
        is_visited[ver] = true;
        for (const int e : graph[ver]) {
          if (!is_visited[e]) {
            path.emplace_back(e);
            if (dfs(e)) return true;
            path.pop_back();
          }
        }
        return false;
      };
  return dfs(s) ? path : std::vector<int>{};
}
