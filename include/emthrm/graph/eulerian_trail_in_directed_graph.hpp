/**
 * @brief オイラー路 有向グラフ版
 * @docs docs/graph/eulerian_trail.md
 */

#ifndef EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_
#define EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_

#include <algorithm>
#include <ranges>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::vector<Edge<CostType>> eulerian_trail_in_directed_graph(
    std::vector<std::vector<Edge<CostType>>> graph, int s = -1) {
  const int n = graph.size();
  int edge_num = 0;
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    edge_num += graph[i].size();
    deg[i] += graph[i].size();
    for (const int e : graph[i] | std::views::transform(&Edge<CostType>::dst)) {
      --deg[e];
    }
  }
  if (edge_num == 0) [[unlikely]] return {};
  const int not0 = n - std::count(deg.begin(), deg.end(), 0);
  if (not0 == 0) {
    if (s == -1) {
      for (int i = 0; i < n; ++i) {
        if (!graph[i].empty()) {
          s = i;
          break;
        }
      }
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
  std::vector<Edge<CostType>> res;
  const auto dfs = [&graph, &res](auto dfs, const int ver) -> void {
    while (!graph[ver].empty()) {
      const Edge<CostType> e = graph[ver].back();
      graph[ver].pop_back();
      dfs(dfs, e.dst);
      res.emplace_back(e);
    }
  };
  dfs(dfs, s);
  if (std::cmp_equal(res.size(), edge_num)) {
    std::reverse(res.begin(), res.end());
    return res;
  }
  return {};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_
