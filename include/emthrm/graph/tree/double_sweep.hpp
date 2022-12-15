#ifndef EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_
#define EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_

#include <cassert>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::pair<CostType, std::vector<int>> double_sweep(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const std::function<std::pair<CostType, int>(int, int)> dfs1 =
      [&graph, &dfs1](const int par, const int ver)
          -> std::pair<CostType, int> {
        std::pair<CostType, int> res{0, ver};
        for (const Edge<CostType>& e : graph[ver]) {
          if (e.dst != par) {
            std::pair<CostType, int> child = dfs1(ver, e.dst);
            child.first += e.cost;
            if (child.first > res.first) res = child;
          }
        }
        return res;
      };
  const int s = dfs1(-1, 0).second;
  CostType diameter;
  int t;
  std::tie(diameter, t) = dfs1(-1, s);
  std::vector<int> path{s};
  const std::function<bool(int, int)> dfs2 =
      [&graph, t, &path, &dfs2](const int par, const int ver) -> bool {
        if (ver == t) return true;
        for (const Edge<CostType>& e : graph[ver]) {
          if (e.dst != par) {
            path.emplace_back(e.dst);
            if (dfs2(ver, e.dst)) return true;
            path.pop_back();
          }
        }
        return false;
      };
  assert(dfs2(-1, s));
  return {diameter, path};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_
