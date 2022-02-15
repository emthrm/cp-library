/**
 * @brief Kruskal 法
 * @docs docs/graph/minimum_spanning_tree.md
 */

#pragma once
#include <algorithm>
#include <vector>

#include "../data_structure/union-find/union-find.hpp"
#include "edge.hpp"

template <typename CostType>
CostType kruskal(const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  std::vector<Edge<CostType>> edges;
  for (int i = 0; i < n; ++i) {
    for (const Edge<CostType>& e : graph[i]) edges.emplace_back(e);
  }
  std::sort(edges.begin(), edges.end());
  CostType res = 0;
  UnionFind uf(n);
  for (const Edge<CostType>& e : edges) {
    if (uf.unite(e.src, e.dst)) res += e.cost;
  }
  return res;
}
