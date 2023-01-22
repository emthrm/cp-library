#ifndef EMTHRM_GRAPH_COST_FREE_ENUMERATE_BRIDGES_HPP_
#define EMTHRM_GRAPH_COST_FREE_ENUMERATE_BRIDGES_HPP_

#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

namespace emthrm {

std::vector<std::pair<int, int>> enumerate_bridges(
    const std::vector<std::vector<int>>& graph) {
  const int n = graph.size();
  std::vector<std::pair<int, int>> res;
  std::vector<int> depth(n, -1), imos(n, 0);
  const std::function<void(int, int)> dfs = [&graph, &res, &depth, &imos, &dfs](
      const int par, const int ver) -> void {
    bool has_multiple_edges = false;
    for (const int e : graph[ver]) {
      if (depth[e] == -1) {
        depth[e] = depth[ver] + 1;
        dfs(ver, e);
        if (imos[e] == 0) res.emplace_back(std::minmax(ver, e));
        imos[ver] += imos[e];
      } else if (!has_multiple_edges && e == par) {
        has_multiple_edges = true;
      } else if (depth[e] < depth[ver]) {
        ++imos[ver];
        --imos[e];
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

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_ENUMERATE_BRIDGES_HPP_
