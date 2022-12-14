#pragma once
#include <algorithm>
#include <functional>
#include <vector>

#include "emthrm/graph/edge.hpp"

template <typename CostType>
std::vector<Edge<CostType>> enumerate_bridges(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<Edge<CostType>> res;
  std::vector<int> depth(n, -1), imos(n, 0);
  const std::function<void(int, int)> dfs = [&graph, &res, &depth, &imos, &dfs](
      const int par, const int ver) -> void {
    bool has_multiple_edges = false;
    for (const Edge<CostType>& e : graph[ver]) {
      if (depth[e.dst] == -1) {
        depth[e.dst] = depth[ver] + 1;
        dfs(ver, e.dst);
        if (imos[e.dst] == 0) {
          res.emplace_back(std::min(ver, e.dst), std::max(ver, e.dst), e.cost);
        }
        imos[ver] += imos[e.dst];
      } else if (!has_multiple_edges && e.dst == par) {
        has_multiple_edges = true;
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
  return res;
}
