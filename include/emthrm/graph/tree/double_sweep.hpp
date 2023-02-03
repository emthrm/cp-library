#ifndef EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_
#define EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_

#include <cassert>
#include <tuple>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::pair<CostType, std::vector<int>> double_sweep(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const auto dfs1 = [&graph](auto dfs1, const int par, const int ver)
      -> std::pair<CostType, int> {
    std::pair<CostType, int> res{0, ver};
    for (const Edge<CostType>& e : graph[ver]) {
      if (e.dst != par) [[unlikely]] {
        std::pair<CostType, int> child = dfs1(dfs1, ver, e.dst);
        child.first += e.cost;
        if (child.first > res.first) res = child;
      }
    }
    return res;
  };
  const int s = dfs1(dfs1, -1, 0).second;
  const auto [diameter, t] = dfs1(dfs1, -1, s);
  std::vector<int> path{s};
  const auto dfs2 = [&graph, t, &path](auto dfs2, const int par, const int ver)
      -> bool {
    if (ver == t) return true;
    for (const Edge<CostType>& e : graph[ver]) {
      if (e.dst != par) [[likely]] {
        path.emplace_back(e.dst);
        if (dfs2(dfs2, ver, e.dst)) return true;
        path.pop_back();
      }
    }
    return false;
  };
  assert(dfs2(dfs2, -1, s));
  return {diameter, path};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_
