#ifndef EMTHRM_GRAPH_COST_FREE_REACHABILITY_ON_DAG_HPP_
#define EMTHRM_GRAPH_COST_FREE_REACHABILITY_ON_DAG_HPP_

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <limits>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/topological_sort.hpp"

namespace emthrm {

std::vector<int> reachability_on_dag(
    const std::vector<std::vector<int>>& graph,
    const std::vector<int>& ss, const std::vector<int>& ts) {
  const int n = graph.size(), q = ss.size();
  assert(std::cmp_equal(ts.size(), q));
  const std::vector<int> order = topological_sort(graph);
  std::vector<int> can_reach(q, false);
  std::vector<std::uint64_t> dp(n, 0);
  for (int i = 0; i < q;) {
    const int j = std::min(i + std::numeric_limits<std::uint64_t>::digits, q);
    std::fill(dp.begin(), dp.end(), 0);
    for (int k = i; k < j; ++k) {
      dp[ss[k]] |= UINT64_C(1) << (k - i);
    }
    for (const int node : order) {
      for (const int e : graph[node]) dp[e] |= dp[node];
    }
    for (int k = i; k < j; ++k) {
      can_reach[k] = dp[ts[k]] >> (k - i) & 1;
    }
    i = j;
  }
  return can_reach;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_REACHABILITY_ON_DAG_HPP_
