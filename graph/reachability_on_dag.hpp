#pragma once
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>
#include "edge.hpp"
#include "topological_sort.hpp"

template <typename CostType>
std::vector<bool> reachability_on_dag(
  const std::vector<std::vector<Edge<CostType>>> &graph,
  const std::vector<int> &src,
  const std::vector<int> &dst
) {
  constexpr int digits = std::numeric_limits<unsigned long long>::digits;
  const int n = graph.size(), q = src.size();
  assert(dst.size() == q);
  std::vector<int> order = topological_sort(graph);
  std::vector<bool> can_reach(q, false);
  std::vector<unsigned long long> dp(n, 0);
  for (int i = 0; i < q;) {
    const int j = std::min(i + digits, q);
    std::fill(dp.begin(), dp.end(), 0);
    for (int k = i; k < j; ++k) {
      dp[src[k]] |= 1ull << (k - i);
    }
    for (const int node : order) {
      for (const Edge<CostType> &e : graph[node]) {
        dp[e.dst] |= dp[node];
      }
    }
    for (int k = i; k < j; ++k) {
      can_reach[k] = dp[dst[k]] >> (k - i) & 1;
    }
    i = j;
  }
  return can_reach;
}
