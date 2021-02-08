#pragma once
#include <algorithm>
#include <functional>
#include <vector>
#include "edge.hpp"

template <typename CostType>
std::vector<Edge<CostType>> detect_bridge(const std::vector<std::vector<Edge<CostType>>> &graph) {
  int n = graph.size();
  std::vector<Edge<CostType>> res;
  std::vector<int> depth(n, -1), imos(n, 0);
  std::function<void(int, int)> dfs = [&graph, &res, &depth, &imos, &dfs](int par, int ver) -> void {
    bool multiedge = false;
    for (const Edge<CostType> &e : graph[ver]) {
      if (depth[e.dst] == -1) {
        depth[e.dst] = depth[ver] + 1;
        dfs(ver, e.dst);
        if (imos[e.dst] == 0) res.emplace_back(std::min(ver, e.dst), std::max(ver, e.dst), e.cost);
        imos[ver] += imos[e.dst];
      } else if (!multiedge && e.dst == par) {
        multiedge = true;
      } else if (depth[e.dst] < depth[ver]) {
        ++imos[ver];
        --imos[e.dst];
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (depth[i] == -1) {
      depth[i] = 0;
      dfs(-1, i);
    }
  }
  // std::sort(res.begin(), res.end(), [](const Edge<CostType> &a, const Edge<CostType> &b) -> bool {
  //   return a.src != b.src ? a.src < b.src : a.dst != b.dst ? a.dst < b.dst : a.cost < b.cost;
  // });
  return res;
}
