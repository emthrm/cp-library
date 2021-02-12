/**
 * @brief Dijkstra 法
 * @docs docs/graph/shortest_path/sssp.md
 */

#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include "../edge.hpp"

template <typename CostType>
struct Dijkstra {
  const CostType inf;

  Dijkstra(const std::vector<std::vector<Edge<CostType>>> &graph,
           const CostType inf = std::numeric_limits<CostType>::max())
  : graph(graph), inf(inf) {}

  std::vector<CostType> build(int s) {
    is_built = true;
    int n = graph.size();
    std::vector<CostType> dist(n, inf);
    dist[s] = 0;
    prev.assign(n, -1);
    using Pci = std::pair<CostType, int>;
    std::priority_queue<Pci, std::vector<Pci>, std::greater<Pci>> que;
    que.emplace(0, s);
    while (!que.empty()) {
      CostType cost; int ver; std::tie(cost, ver) = que.top(); que.pop();
      if (dist[ver] < cost) continue;
      for (const Edge<CostType> &e : graph[ver]) {
        if (dist[e.dst] > dist[ver] + e.cost) {
          dist[e.dst] = dist[ver] + e.cost;
          prev[e.dst] = ver;
          que.emplace(dist[e.dst], e.dst);
        }
      }
    }
    return dist;
  }

  std::vector<int> build_path(int t) const {
    assert(is_built);
    std::vector<int> res;
    for (; t != -1; t = prev[t]) res.emplace_back(t);
    std::reverse(res.begin(), res.end());
    return res;
  }

private:
  bool is_built = false;
  std::vector<std::vector<Edge<CostType>>> graph;
  std::vector<int> prev;
};
