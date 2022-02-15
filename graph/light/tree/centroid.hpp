#pragma once
#include <algorithm>
#include <functional>
#include <vector>

std::vector<int> centroid(const std::vector<std::vector<int>>& graph) {
  const int n = graph.size();
  std::vector<int> subtree(n, 1), res;
  const std::function<void(int, int)> dfs =
      [&graph, n, &subtree, &res, &dfs](const int par, const int ver) {
        bool is_centroid = true;
        for (const int e : graph[ver]) {
          if (e != par) {
            dfs(ver, e);
            subtree[ver] += subtree[e];
            is_centroid &= subtree[e] <= n / 2;
          }
        }
        if (is_centroid && n - subtree[ver] <= n / 2) res.emplace_back(ver);
      };
  dfs(-1, 0);
  std::sort(res.begin(), res.end());
  return res;
}
