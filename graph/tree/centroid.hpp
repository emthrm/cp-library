#pragma once
#include <algorithm>
#include <functional>
#include <vector>

#include "../edge.hpp"

template <typename CostType>
std::vector<int> centroid(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> subtree(n, 1), res;
  const std::function<void(int, int)> dfs =
      [&graph, n, &subtree, &res, &dfs](const int par, const int ver) -> void {
        bool is_centroid = true;
        for (const Edge<CostType>& e : graph[ver]) {
          if (e.dst != par) {
            dfs(ver, e.dst);
            subtree[ver] += subtree[e.dst];
            is_centroid &= subtree[e.dst] <= n / 2;
          }
        }
        if (is_centroid && n - subtree[ver] <= n / 2) res.emplace_back(ver);
      };
  dfs(-1, 0);
  std::sort(res.begin(), res.end());
  return res;
}
