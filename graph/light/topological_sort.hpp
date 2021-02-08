#pragma once
#include <queue>
#include <vector>

std::vector<int> topological_sort(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>();
}
