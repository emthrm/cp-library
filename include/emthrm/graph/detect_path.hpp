#ifndef EMTHRM_GRAPH_DETECT_PATH_HPP_
#define EMTHRM_GRAPH_DETECT_PATH_HPP_

#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::vector<Edge<CostType>> detect_path(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const int s, const int t) {
  std::vector<bool> is_visited(graph.size(), false);
  std::vector<Edge<CostType>> path;
  const auto dfs = [&graph, t, &is_visited, &path](auto dfs, const int ver)
      -> bool {
    if (ver == t) return true;
    is_visited[ver] = true;
    for (const Edge<CostType>& e : graph[ver]) {
      if (!is_visited[e.dst]) {
        path.emplace_back(e);
        if (dfs(dfs, e.dst)) return true;
        path.pop_back();
      }
    }
    return false;
  };
  dfs(dfs, s);
  return path;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_DETECT_PATH_HPP_
