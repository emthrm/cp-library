#ifndef EMTHRM_GRAPH_COST_FREE_DETECT_PATH_HPP_
#define EMTHRM_GRAPH_COST_FREE_DETECT_PATH_HPP_

#include <vector>

namespace emthrm {

std::vector<int> detect_path(const std::vector<std::vector<int>>& graph,
                             const int s, const int t) {
  std::vector<bool> is_visited(graph.size(), false);
  std::vector<int> path{s};
  const auto dfs = [&graph, t, &is_visited, &path](auto dfs, const int ver)
      -> bool {
    if (ver == t) return true;
    is_visited[ver] = true;
    for (const int e : graph[ver]) {
      if (!is_visited[e]) {
        path.emplace_back(e);
        if (dfs(dfs, e)) return true;
        path.pop_back();
      }
    }
    return false;
  };
  return dfs(dfs, s) ? path : std::vector<int>{};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_DETECT_PATH_HPP_
