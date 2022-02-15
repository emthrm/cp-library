/**
 * @brief Dijkstra 法
 * @docs docs/graph/shortest_path/single-source_shortest_path_problem.md
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

  Dijkstra(const std::vector<std::vector<Edge<CostType>>>& graph,
           const CostType inf = std::numeric_limits<CostType>::max())
      : inf(inf), is_built(false), graph(graph) {}

  std::vector<CostType> build(const int s) {
    is_built = true;
    const int n = graph.size();
    std::vector<CostType> dist(n, inf);
    dist[s] = 0;
    prev.assign(n, -1);
    std::priority_queue<std::pair<CostType, int>,
                        std::vector<std::pair<CostType, int>>,
                        std::greater<std::pair<CostType, int>>> que;
    que.emplace(0, s);
    while (!que.empty()) {
      CostType d;
      int ver;
      std::tie(d, ver) = que.top();
      que.pop();
      if (d > dist[ver]) continue;
      for (const Edge<CostType>& e : graph[ver]) {
        if (dist[ver] + e.cost < dist[e.dst]) {
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
    for (; t != -1; t = prev[t]) {
      res.emplace_back(t);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }

private:
  bool is_built;
  std::vector<int> prev;
  std::vector<std::vector<Edge<CostType>>> graph;
};
