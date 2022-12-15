#ifndef EMTHRM_GRAPH_COST_FREE_TREE_DOUBLE_SWEEP_HPP_
#define EMTHRM_GRAPH_COST_FREE_TREE_DOUBLE_SWEEP_HPP_

#include <cassert>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

namespace emthrm {

std::pair<int, std::vector<int>> double_sweep(
    const std::vector<std::vector<int>>& graph) {
  const std::function<std::pair<int, int>(int, int)> dfs1 =
      [&graph, &dfs1](const int par, const int ver) -> std::pair<int, int> {
        std::pair<int, int> res{0, ver};
        for (const int e : graph[ver]) {
          if (e != par) {
            std::pair<int, int> child = dfs1(ver, e);
            ++child.first;
            if (child.first > res.first) res = child;
          }
        }
        return res;
      };
  const int s = dfs1(-1, 0).second;
  int diameter, t;
  std::tie(diameter, t) = dfs1(-1, s);
  std::vector<int> path{s};
  const std::function<bool(int, int)> dfs2 =
      [&graph, t, &path, &dfs2](const int par, const int ver) -> bool {
        if (ver == t) return true;
        for (const int e : graph[ver]) {
          if (e != par) {
            path.emplace_back(e);
            if (dfs2(ver, e)) return true;
            path.pop_back();
          }
        }
        return false;
      };
  assert(dfs2(-1, s));
  return {diameter, path};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_TREE_DOUBLE_SWEEP_HPP_
