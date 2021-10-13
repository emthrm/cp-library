#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <vector>
#include "edge.hpp"
#include "topological_sort.hpp"

template <typename CostType>
std::vector<int> reachability_on_dag(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const std::vector<int>& src,
    const std::vector<int>& dst) {
  constexpr int DIGITS = 64;
  const int n = graph.size(), q = src.size();
  assert(dst.size() == q);
  const std::vector<int> order = topological_sort(graph);
  std::vector<int> can_reach(q, false);
  std::vector<std::uint64_t> dp(n, 0);
  for (int i = 0; i < q;) {
    const int j = std::min(i + DIGITS, q);
    std::fill(dp.begin(), dp.end(), 0);
    for (int k = i; k < j; ++k) {
      dp[src[k]] |= UINT64_C(1) << (k - i);
    }
    for (const int node : order) {
      for (const Edge<CostType>& e : graph[node]) {
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
