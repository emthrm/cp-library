#ifndef EMTHRM_GRAPH_TRAVELING_SALESMAN_PROBLEM_HPP_
#define EMTHRM_GRAPH_TRAVELING_SALESMAN_PROBLEM_HPP_

#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
CostType traveling_salesman_problem(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const CostType inf = std::numeric_limits<CostType>::max()) {
  const int n = graph.size();
  if (n == 1) [[unlikely]] return 0;
  std::vector<std::vector<CostType>> dp(1 << n, std::vector<CostType>(n, inf));
  dp[1][0] = 0;
  for (int i = 1; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i][j] == inf) continue;
      for (const Edge<CostType>& e : graph[j]) {
        if (i >> e.dst & 1) continue;
        dp[i | (1 << e.dst)][e.dst] =
            std::min(dp[i | (1 << e.dst)][e.dst], dp[i][j] + e.cost);
      }
    }
  }
  CostType res = inf;
  for (int j = 1; j < n; ++j) {
    if (dp.back()[j] == inf) continue;
    for (const Edge<CostType>& e : graph[j]) {
      if (e.dst == 0) res = std::min(res, dp.back()[j] + e.cost);
    }
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_TRAVELING_SALESMAN_PROBLEM_HPP_
