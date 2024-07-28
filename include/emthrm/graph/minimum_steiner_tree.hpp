#ifndef EMTHRM_GRAPH_MINIMUM_STEINER_TREE_HPP_
#define EMTHRM_GRAPH_MINIMUM_STEINER_TREE_HPP_

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <ranges>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
CostType minimum_steiner_tree(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    std::vector<int> terminals) {
  if (terminals.empty()) [[unlikely]] return 0;
  const CostType inf = std::numeric_limits<CostType>::max();
  const int n = graph.size();
  std::ranges::sort(terminals);
  terminals.erase(
      std::unique(terminals.begin(), terminals.end()), terminals.end());
  const int m = terminals.size();
  if (m == 1) [[unlikely]] return 0;
  std::vector dp(1 << (m - 1), std::vector(n, inf));
  for (const int i : std::views::iota(0, m - 1)) {
    dp[1 << i][terminals[i]] = 0;
  }
  std::priority_queue<std::pair<CostType, int>,
                      std::vector<std::pair<CostType, int>>,
                      std::greater<std::pair<CostType, int>>> que;
  for (const int bit : std::views::iota(1, 1 << (m - 1))) {
    for (const int i : std::views::iota(0, n)) {
      for (int sub = bit; sub > 0; sub = (sub - 1) & bit) {
        if (dp[sub][i] == inf || dp[bit ^ sub][i] == inf) continue;
        dp[bit][i] = std::min(dp[bit][i], dp[sub][i] + dp[bit ^ sub][i]);
      }
    }
    for (const int i : std::views::iota(0, n)) {
      if (dp[bit][i] != inf) que.emplace(dp[bit][i], i);
    }
    while (!que.empty()) {
      const auto [cur_cost, vertex] = que.top();
      que.pop();
      if (cur_cost > dp[bit][vertex]) continue;
      for (const Edge<CostType>& e : graph[vertex]) {
        if (const CostType tmp = dp[bit][vertex] + e.cost;
            tmp < dp[bit][e.dst]) {
          dp[bit][e.dst] = tmp;
          que.emplace(dp[bit][e.dst], e.dst);
        }
      }
    }
  }
  return dp.back()[terminals.back()];
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_MINIMUM_STEINER_TREE_HPP_
