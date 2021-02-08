#pragma once
#include <algorithm>
#include <functional>
#include <vector>

std::vector<int> centroid(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> subtree(n, 1), res;
  std::function<void(int, int)> dfs = [&graph, n, &subtree, &res, &dfs](int par, int ver) {
    bool is_centroid = true;
    for (int e : graph[ver]) {
      if (e != par) {
        dfs(ver, e);
        subtree[ver] += subtree[e];
        is_centroid &= subtree[e] <= n / 2;
      }
    }
    if (is_centroid && (n - subtree[ver]) <= n / 2) res.emplace_back(ver);
  };
  dfs(-1, 0);
  std::sort(res.begin(), res.end());
  return res;
}
