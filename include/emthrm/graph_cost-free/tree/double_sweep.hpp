#ifndef EMTHRM_GRAPH_COST_FREE_TREE_DOUBLE_SWEEP_HPP_
#define EMTHRM_GRAPH_COST_FREE_TREE_DOUBLE_SWEEP_HPP_

#include <cassert>
#include <tuple>
#include <utility>
#include <vector>

namespace emthrm {

std::pair<int, std::vector<int>> double_sweep(
    const std::vector<std::vector<int>>& graph) {
  const auto dfs1 = [&graph](auto dfs1, const int par, const int ver)
      -> std::pair<int, int> {
    std::pair<int, int> res{0, ver};
    for (const int e : graph[ver]) {
      if (e != par) {
        std::pair<int, int> child = dfs1(dfs1, ver, e);
        ++child.first;
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
    for (const int e : graph[ver]) {
      if (e != par) {
        path.emplace_back(e);
        if (dfs2(dfs2, ver, e)) return true;
        path.pop_back();
      }
    }
    return false;
  };
  assert(dfs2(dfs2, -1, s));
  return {diameter, path};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_TREE_DOUBLE_SWEEP_HPP_
