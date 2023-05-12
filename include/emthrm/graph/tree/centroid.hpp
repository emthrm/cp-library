#ifndef EMTHRM_GRAPH_TREE_CENTROID_HPP_
#define EMTHRM_GRAPH_TREE_CENTROID_HPP_

#include <algorithm>
#include <ranges>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::vector<int> centroid(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> subtree(n, 1), res;
  const auto dfs = [&graph, n, &subtree, &res](
      auto dfs, const int par, const int ver) -> void {
    bool is_centroid = true;
    for (const int e : graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (e != par) {
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

#endif  // EMTHRM_GRAPH_TREE_CENTROID_HPP_
