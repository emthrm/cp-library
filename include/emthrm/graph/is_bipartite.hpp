#ifndef EMTHRM_GRAPH_IS_BIPARTITE_HPP_
#define EMTHRM_GRAPH_IS_BIPARTITE_HPP_

#include <ranges>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::vector<int> is_bipartite(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> color(n, -1);
  const auto dfs = [&graph, &color](auto dfs, const int ver, const int c)
      -> bool {
    color[ver] = c;
    for (const int e : graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (color[e] == c || (color[e] == -1 && !dfs(dfs, e, c ^ 1))) {
        return false;
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1 && !dfs(dfs, i, 0)) return std::vector<int>{};
  }
  return color;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_IS_BIPARTITE_HPP_
