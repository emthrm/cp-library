#pragma once
#include <limits>
#include <numeric>
#include <vector>
#include "edge.hpp"

template <typename CostType>
CostType traveling_salesman_problem(
  const std::vector<std::vector<Edge<CostType>>> &graph,
  const CostType inf = std::numeric_limits<CostType>::max()
) {
  int n = graph.size();
  if (n == 1) return 0;
  std::vector<std::vector<CostType>> dp(1 << n, std::vector<CostType>(n, inf));
  dp[1][0] = 0;
  for (int i = 1; i < (1 << n); ++i) for (int j = 0; j < n; ++j) {
    if (dp[i][j] == inf) continue;
    for (const Edge<CostType> &e : graph[j]) {
      if (i >> e.dst & 1) continue;
      CostType tmp = dp[i][j] + e.cost;
      if (tmp < dp[i | (1 << e.dst)][e.dst]) dp[i | (1 << e.dst)][e.dst] = tmp;
    }
  }
  CostType res = inf;
  for (int j = 1; j < n; ++j) {
    if (dp[(1 << n) - 1][j] == inf) continue;
    for (const Edge<CostType> &e : graph[j]) {
      if (e.dst == 0) {
        CostType tmp = dp[(1 << n) - 1][j] + e.cost;
        if (tmp < res) res = tmp;
      }
    }
  }
  return res;
}
