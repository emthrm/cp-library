/**
 * @brief 内周 有向グラフ版
 * @docs docs/graph/girth.md
 */

#ifndef EMTHRM_GRAPH_GIRTH_IN_DIRECTED_GRAPH_HPP_
#define EMTHRM_GRAPH_GIRTH_IN_DIRECTED_GRAPH_HPP_

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#if __cplusplus < 201703L
#include <tuple>
#endif
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
CostType girth_in_directed_graph(
    const std::vector<std::vector<Edge<CostType>>>& graph,
    const CostType inf = std::numeric_limits<CostType>::max()) {
  const int n = graph.size();
  CostType res = inf;
  std::vector<CostType> dist(n);
  std::priority_queue<std::pair<CostType, int>,
                      std::vector<std::pair<CostType, int>>,
                      std::greater<std::pair<CostType, int>>> que;
  for (int root = 0; root < n; ++root) {
    std::fill(dist.begin(), dist.end(), inf);
    dist[root] = 0;
    que.emplace(dist[root], root);
    while (!que.empty()) {
#if __cplusplus >= 201703L
      const auto [d, ver] = que.top();
#else
      CostType d;
      int ver;
      std::tie(d, ver) = que.top();
#endif
      que.pop();
      if (d > dist[ver]) continue;
      for (const Edge<CostType>& e : graph[ver]) {
        const CostType nxt = dist[ver] + e.cost;
        if (nxt < dist[e.dst]) {
          dist[e.dst] = nxt;
          que.emplace(nxt, e.dst);
        } else if (e.dst == root) {
          res = std::min(res, nxt);
        }
      }
    }
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_GIRTH_IN_DIRECTED_GRAPH_HPP_
