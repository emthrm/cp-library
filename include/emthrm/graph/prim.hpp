/**
 * @brief Prim 法
 * @docs docs/graph/minimum_spanning_tree.md
 */

#ifndef EMTHRM_GRAPH_PRIM_HPP_
#define EMTHRM_GRAPH_PRIM_HPP_

#include <functional>
#include <queue>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
CostType prim(const std::vector<std::vector<Edge<CostType>>>& graph,
              const int root = 0) {
  const int n = graph.size();
  CostType res = 0;
  std::vector<bool> is_visited(n, false);
  is_visited[root] = true;
  std::priority_queue<Edge<CostType>,
                      std::vector<Edge<CostType>>,
                      std::greater<Edge<CostType>>> que;
  for (const Edge<CostType>& e : graph[root]) {
    if (e.dst != root) que.emplace(e);
  }
  while (!que.empty()) {
    const Edge<CostType> e1 = que.top();
    que.pop();
    if (is_visited[e1.dst]) continue;
    is_visited[e1.dst] = true;
    res += e1.cost;
    for (const Edge<CostType>& e2 : graph[e1.dst]) {
      if (!is_visited[e2.dst]) que.emplace(e2);
    }
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_PRIM_HPP_
