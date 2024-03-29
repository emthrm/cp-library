#ifndef EMTHRM_GRAPH_COST_FREE_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_
#define EMTHRM_GRAPH_COST_FREE_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_

#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

namespace emthrm {

std::vector<int> eulerian_trail_in_directed_graph(
    std::vector<std::vector<int>> graph, int s = -1) {
  const int n = graph.size();
  int edge_num = 0;
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    edge_num += graph[i].size();
    deg[i] += graph[i].size();
    for (const int e : graph[i]) --deg[e];
  }
  const int not0 = n - std::count(deg.begin(), deg.end(), 0);
  if (not0 == 0) {
    if (s == -1) {
      s = std::distance(
          graph.begin(),
          std::find_if_not(graph.begin(), graph.end(),
                           [](const std::vector<int>& edges) -> bool {
                             return edges.empty();
                           }));
    }
  } else if (not0 == 2) {
    bool t_exists = false;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 0) continue;
      if (deg[i] == 1) {
        if (s == -1) s = i;
        if (s != i) return {};
      } else if (deg[i] == -1) {
        if (t_exists) return {};
        t_exists = true;
      } else {
        return {};
      }
    }
  } else {
    return {};
  }
  std::vector<int> res;
  const auto dfs = [&graph, &res](auto dfs, const int ver) -> void {
    while (!graph[ver].empty()) {
      const int nxt = graph[ver].back();
      graph[ver].pop_back();
      dfs(dfs, nxt);
    }
    res.emplace_back(ver);
  };
  dfs(dfs, s);
  if (std::cmp_equal(res.size(), edge_num + 1)) {
    std::reverse(res.begin(), res.end());
    return res;
  }
  return {};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_
