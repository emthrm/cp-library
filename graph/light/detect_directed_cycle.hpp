#pragma once
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

std::vector<int> detect_directed_cycle(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> visited(n, 0), cycle;
  std::vector<std::pair<int, int>> edges;
  std::function<bool(int)> dfs = [&graph, &visited, &edges, &cycle, &dfs](int ver) -> bool {
    visited[ver] = 1;
    for (int e : graph[ver]) {
      if (visited[e] == 1) {
        cycle.emplace_back(ver);
        while (edges.back().first != e) {
          cycle.emplace_back(edges.back().first);
          edges.pop_back();
        }
        cycle.emplace_back(e);
        std::reverse(cycle.begin(), cycle.end());
        return true;
      } else if (visited[e] == 0) {
        edges.emplace_back(ver, e);
        if (dfs(e)) return true;
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
