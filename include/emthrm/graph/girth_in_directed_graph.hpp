/**
 * @brief 内周 有向グラフ版
 * @docs docs/graph/girth.md
 */

#pragma once
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

#include "./edge.hpp"

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
      CostType d;
      int ver;
      std::tie(d, ver) = que.top();
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
