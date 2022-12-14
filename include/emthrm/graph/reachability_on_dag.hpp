#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <limits>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/topological_sort.hpp"

template <typename CostType>
std::vector<bool> reachability_on_dag(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const std::vector<int>& ss, const std::vector<int>& ts) {
  const int n = graph.size(), q = ss.size();
  assert(static_cast<int>(ts.size()) == q);
  const std::vector<int> order = topological_sort(graph);
  std::vector<bool> can_reach(q, false);
  std::vector<std::uint64_t> dp(n, 0);
  for (int i = 0; i < q;) {
    const int j = std::min(i + std::numeric_limits<std::uint64_t>::digits, q);
    std::fill(dp.begin(), dp.end(), 0);
    for (int k = i; k < j; ++k) {
      dp[ss[k]] |= UINT64_C(1) << (k - i);
    }
    for (const int node : order) {
      for (const Edge<CostType>& e : graph[node]) dp[e.dst] |= dp[node];
    }
    for (int k = i; k < j; ++k) {
      can_reach[k] = dp[ts[k]] >> (k - i) & 1;
    }
    i = j;
  }
  return can_reach;
}
