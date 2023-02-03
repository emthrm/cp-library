#ifndef EMTHRM_GRAPH_COST_FREE_TREE_CENTROID_HPP_
#define EMTHRM_GRAPH_COST_FREE_TREE_CENTROID_HPP_

#include <algorithm>
#include <vector>

namespace emthrm {

std::vector<int> centroid(const std::vector<std::vector<int>>& graph) {
  const int n = graph.size();
  std::vector<int> subtree(n, 1), res;
  const auto dfs = [&graph, n, &subtree, &res](
      auto dfs, const int par, const int ver) -> void {
    bool is_centroid = true;
    for (const int e : graph[ver]) {
      if (e != par) [[likely]] {
        dfs(dfs, ver, e);
        subtree[ver] += subtree[e];
        is_centroid &= subtree[e] <= n / 2;
      }
    }
    if (is_centroid && n - subtree[ver] <= n / 2) res.emplace_back(ver);
  };
  dfs(dfs, -1, 0);
  std::sort(res.begin(), res.end());
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_TREE_CENTROID_HPP_
