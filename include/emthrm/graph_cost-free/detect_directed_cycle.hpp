#ifndef EMTHRM_GRAPH_COST_FREE_DETECT_DIRECTED_CYCLE_HPP_
#define EMTHRM_GRAPH_COST_FREE_DETECT_DIRECTED_CYCLE_HPP_

#include <algorithm>
#include <utility>
#include <vector>

namespace emthrm {

std::vector<int> detect_directed_cycle(
    const std::vector<std::vector<int>>& graph) {
  const int n = graph.size();
  std::vector<int> is_visited(n, 0), cycle;
  const auto dfs = [&graph, &is_visited, &cycle](auto dfs, const int ver)
      -> bool {
    is_visited[ver] = 1;
    cycle.emplace_back(ver);
    for (const int e : graph[ver]) {
      if (is_visited[e] == 1) {
        cycle.erase(cycle.begin(), std::find(cycle.begin(), cycle.end(), e));
        cycle.emplace_back(e);
        return true;
      } else if (is_visited[e] == 0) {
        if (dfs(dfs, e)) return true;
      }
    }
    cycle.pop_back();
    is_visited[ver] = 2;
    return false;
  };
  for (int i = 0; i < n; ++i) {
    if (is_visited[i] == 0 && dfs(dfs, i)) break;
  }
  return cycle;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_DETECT_DIRECTED_CYCLE_HPP_
