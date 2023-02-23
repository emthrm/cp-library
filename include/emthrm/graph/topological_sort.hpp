#ifndef EMTHRM_GRAPH_TOPOLOGICAL_SORT_HPP_
#define EMTHRM_GRAPH_TOPOLOGICAL_SORT_HPP_

#include <queue>
#include <ranges>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
std::vector<int> topological_sort(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<int> deg(n, 0);
  for (const int e : graph
                   | std::views::join
                   | std::views::transform(&Edge<CostType>::dst)) {
    ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  res.reserve(n);
  while (!que.empty()) {
    const int ver = que.front();
    que.pop();
    res.emplace_back(ver);
    for (const int e : graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return std::cmp_equal(res.size(), n) ? res : std::vector<int>{};
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_TOPOLOGICAL_SORT_HPP_
