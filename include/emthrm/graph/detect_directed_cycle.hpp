#ifndef EMTHRM_GRAPH_DETECT_DIRECTED_CYCLE_HPP_
#define EMTHRM_GRAPH_DETECT_DIRECTED_CYCLE_HPP_

#include <algorithm>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::vector<Edge<CostType>> detect_directed_cycle(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> is_visited(n, 0);
  std::vector<Edge<CostType>> edges, cycle;
  const auto dfs = [&graph, &is_visited, &edges, &cycle](
      auto dfs, const int ver) -> bool {
    is_visited[ver] = 1;
    for (const Edge<CostType>& e : graph[ver]) {
      if (is_visited[e.dst] == 1) {
        cycle.emplace_back(e);
        while (cycle.back().src != e.dst) {
          cycle.emplace_back(edges.back());
          edges.pop_back();
        }
        std::reverse(cycle.begin(), cycle.end());
        return true;
      } else if (is_visited[e.dst] == 0) {
        edges.emplace_back(e);
        if (dfs(dfs, e.dst)) return true;
        edges.pop_back();
      }
    }
    is_visited[ver] = 2;
    return false;
  };
  for (int i = 0; i < n; ++i) {
    if (is_visited[i] == 0 && dfs(dfs, i)) break;
  }
  return cycle;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_DETECT_DIRECTED_CYCLE_HPP_
