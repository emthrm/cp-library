/**
 * @brief 木の直径 全方位木 DP 版
 * @docs docs/graph/tree/diameter.md
 */

#pragma once
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include "../edge.hpp"

template <typename CostType>
CostType rerooting(const std::vector<std::vector<Edge<CostType>>> &graph) {
  int n = graph.size();
  std::vector<CostType> dist(n, 0);
  std::vector<std::vector<std::pair<CostType, int>>> children(n);
  std::function<void(int, int)> dfs1 = [&graph, &dist, &children, &dfs1](int par, int ver) -> void {
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) {
        dfs1(ver, e.dst);
        if (dist[e.dst] + e.cost > dist[ver]) dist[ver] = dist[e.dst] + e.cost;
        children[ver].emplace_back(dist[e.dst] + e.cost, e.dst);
      }
    }
  };
  dfs1(-1, 0);
  std::vector<CostType> dp(n);
  std::function<void(int, int, CostType)> dfs2 = [&graph, &children, &dp, &dfs2](int par, int ver, CostType par_dp) -> void {
    if (par != -1) children[ver].emplace_back(par_dp, par);
    std::sort(children[ver].begin(), children[ver].end(), std::greater<std::pair<CostType, int>>());
    if (children[ver].size() == 1) {
      dp[ver] = children[ver].front().first;
      if (par == -1) {
        const Edge<CostType> &e = graph[ver].front();
        dfs2(ver, e.dst, e.cost);
      }
    } else {
      dp[ver] = children[ver][0].first + children[ver][1].first;
      for (const Edge<CostType> &e : graph[ver]) {
        if (e.dst != par) dfs2(ver, e.dst, children[ver][children[ver][0].second == e.dst ? 1 : 0].first + e.cost);
      }
    }
  };
  if (n == 1) {
    dp[0] = 0;
  } else {
    dfs2(-1, 0, 0);
  }
  return *std::max_element(dp.begin(), dp.end());
}
