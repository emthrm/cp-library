#ifndef EMTHRM_GRAPH_COST_FREE_TREE_REROOTING_DP_HPP_
#define EMTHRM_GRAPH_COST_FREE_TREE_REROOTING_DP_HPP_

#include <algorithm>
#include <vector>

namespace emthrm {

template <typename CommutativeSemigroup, typename E, typename F, typename G>
std::vector<CommutativeSemigroup> rerooting_dp(
    const std::vector<std::vector<int>>& graph,
    const std::vector<CommutativeSemigroup>& def,
    const E merge, const F f, const G g) {
  const int n = graph.size();
  if (n == 0) [[unlikely]] return {};
  if (n == 1) [[unlikely]] return {g(def[0], 0)};
  std::vector<std::vector<CommutativeSemigroup>> children(n);
  const auto dfs1 = [&graph, &def, merge, f, g, &children](
      auto dfs1, const int par, const int ver) -> CommutativeSemigroup {
    children[ver].reserve(graph[ver].size());
    CommutativeSemigroup dp = def[ver];
    for (const int e : graph[ver]) {
      if (e == par) [[unlikely]] {
        children[ver].emplace_back();
      } else {
        children[ver].emplace_back(f(dfs1(dfs1, ver, e), ver, e));
        dp = merge(dp, children[ver].back());
      }
    }
    return g(dp, ver);
  };
  dfs1(dfs1, -1, 0);
  std::vector<CommutativeSemigroup> dp = def;
  const auto dfs2 = [&graph, &def, merge, f, g, &children, &dp](
      auto dfs2, const int par, const int ver, const CommutativeSemigroup& m)
          -> void {
    const int c = graph[ver].size();
    for (int i = 0; i < c; ++i) {
      if (graph[ver][i] == par) [[unlikely]] {
        children[ver][i] = f(m, ver, graph[ver][i]);
        break;
      }
    }
    std::vector<CommutativeSemigroup> left{def[ver]}, right;
    left.reserve(c);
    for (int i = 0; i < c - 1; ++i) {
      left.emplace_back(merge(left[i], children[ver][i]));
    }
    dp[ver] = g(merge(left.back(), children[ver].back()), ver);
    if (c >= 2) {
      right.reserve(c - 1);
      right.emplace_back(children[ver].back());
      for (int i = c - 2; i > 0; --i) {
        right.emplace_back(merge(children[ver][i], right[c - 2 - i]));
      }
      std::reverse(right.begin(), right.end());
    }
    for (int i = 0; i < c; ++i) {
      if (graph[ver][i] != par) [[likely]] {
        dfs2(dfs2, ver, graph[ver][i],
             g(i + 1 == c ? left[i] : merge(left[i], right[i]), ver));
      }
    }
  };
  dfs2(dfs2, -1, 0, CommutativeSemigroup());
  return dp;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_TREE_REROOTING_DP_HPP_
