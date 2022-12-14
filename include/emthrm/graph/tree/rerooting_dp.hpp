#pragma once
#include <algorithm>
#include <functional>
#include <vector>

#include "emthrm/graph/edge.hpp"

template <typename CostType, typename CommutativeSemigroup,
          typename E, typename F, typename G>
std::vector<CommutativeSemigroup> rerooting_dp(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const std::vector<CommutativeSemigroup>& def,
    const E merge, const F f, const G g) {
  const int n = graph.size();
  if (n == 0) return {};
  if (n == 1) return {g(def[0], 0)};
  std::vector<std::vector<CommutativeSemigroup>> children(n);
  const std::function<CommutativeSemigroup(const int, const int)> dfs1 =
      [&graph, &def, merge, f, g, &children, &dfs1](
          const int par, const int ver) -> CommutativeSemigroup {
        children[ver].reserve(graph[ver].size());
        CommutativeSemigroup dp = def[ver];
        for (const Edge<CostType>& e : graph[ver]) {
          if (e.dst == par) {
            children[ver].emplace_back();
          } else {
            children[ver].emplace_back(f(dfs1(ver, e.dst), e));
            dp = merge(dp, children[ver].back());
          }
        }
        return g(dp, ver);
      };
  dfs1(-1, 0);
  std::vector<CommutativeSemigroup> dp = def;
  const std::function<void(const int, const int,
                           const CommutativeSemigroup&)> dfs2 =
      [&graph, &def, merge, f, g, &children, &dp, &dfs2](
          const int par, const int ver, const CommutativeSemigroup& m) -> void {
        const int c = graph[ver].size();
        for (int i = 0; i < c; ++i) {
          if (graph[ver][i].dst == par) {
            children[ver][i] = f(m, graph[ver][i]);
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
          if (graph[ver][i].dst != par) {
            dfs2(ver, graph[ver][i].dst,
                 g(i + 1 == c ? left[i] : merge(left[i], right[i]), ver));
          }
        }
      };
  dfs2(-1, 0, CommutativeSemigroup());
  return dp;
}
