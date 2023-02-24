/**
 * @title Bellman–Ford 法
 * @docs docs/graph/shortest_path/single-source_shortest_path_problem.md
 */

#ifndef EMTHRM_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP_
#define EMTHRM_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP_

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
struct BellmanFord {
  const CostType inf;
  std::vector<CostType> dist;

  BellmanFord(const std::vector<std::vector<Edge<CostType>>>& graph,
              const CostType inf = std::numeric_limits<CostType>::max())
      : inf(inf), is_built(false), graph(graph) {}

  bool has_negative_cycle(const int s) {
    is_built = true;
    const int n = graph.size();
    dist.assign(n, inf);
    dist[s] = 0;
    prev.assign(n, -1);
    for (int step = 0; step < n; ++step) {
      bool is_updated = false;
      for (int i = 0; i < n; ++i) {
        if (dist[i] == inf) continue;
        for (const Edge<CostType>& e : graph[i]) {
          if (dist[e.dst] > dist[i] + e.cost) {
            dist[e.dst] = dist[i] + e.cost;
            prev[e.dst] = i;
            is_updated = true;
          }
        }
      }
      if (!is_updated) return false;
    }
    return true;
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

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP_
