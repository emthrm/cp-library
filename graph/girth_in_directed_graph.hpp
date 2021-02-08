/**
 * @brief 内周 有向グラフ版
 * @docs docs/graph/girth.md
 */

#pragma once
#include <algorithm>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include "edge.hpp"

template <typename CostType>
CostType girth_in_directed_graph(const std::vector<std::vector<Edge<CostType>>> &graph, const CostType CINF) {
  int n = graph.size();
  CostType res = CINF;
  std::vector<CostType> dist(n);
  using Pci = std::pair<CostType, int>;
  std::priority_queue<Pci, std::vector<Pci>, std::greater<Pci>> que;
  for (int root = 0; root < n; ++root) {
    std::fill(dist.begin(), dist.end(), CINF);
    dist[root] = 0;
    que.emplace(0, root);
    while (!que.empty()) {
      CostType cost; int ver; std::tie(cost, ver) = que.top(); que.pop();
      if (dist[ver] < cost) continue;
      for (const Edge<CostType> &e : graph[ver]) {
        CostType cost = dist[ver] + e.cost;
        if (cost < dist[e.dst]) {
          dist[e.dst] = cost;
          que.emplace(cost, e.dst);
        } else if (e.dst == root) {
          if (cost < res) res = cost;
        }
      }
    }
  }
  return res;
}
