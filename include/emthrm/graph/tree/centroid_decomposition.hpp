#ifndef EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_
#define EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_

#include <ranges>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
struct CentroidDecomposition {
  int root;
  std::vector<int> parent;
  std::vector<std::vector<int>> g;

  explicit CentroidDecomposition(
      const std::vector<std::vector<Edge<CostType>>>& graph)
      : graph(graph) {
    const int n = graph.size();
    parent.assign(n, -1);
    g.resize(n);
    is_alive.assign(n, true);
    subtree.resize(n);
    root = build(0);
  }

 private:
  std::vector<bool> is_alive;
  std::vector<int> subtree;
  const std::vector<std::vector<Edge<CostType>>> graph;

  int build(const int s) {
    const int centroid = search_centroid(-1, s, calc_subtree(-1, s) / 2);
    is_alive[centroid] = false;
    for (const int e : graph[centroid]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (is_alive[e]) {
        const int child = build(e);
        g[centroid].emplace_back(child);
        parent[child] = centroid;
      }
    }
    is_alive[centroid] = true;
    return centroid;
  }

  int calc_subtree(const int par, const int ver) {
    subtree[ver] = 1;
    for (const int e : graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (e != par && is_alive[e]) {
        subtree[ver] += calc_subtree(ver, e);
      }
    }
    return subtree[ver];
  }

  int search_centroid(const int par, const int ver, const int half) const {
    for (const int e : graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (e != par && is_alive[e] && subtree[e] > half) {
        return search_centroid(ver, e, half);
      }
    }
    return ver;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_
