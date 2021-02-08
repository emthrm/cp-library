/**
 * @brief Kruskal 法 重量版
 * @docs docs/graph/mst/mst.md
 */

#pragma once
#include <algorithm>
#include <vector>
#include "../edge.hpp"
#include "../../data_structure/union-find/union-find.hpp"

template <typename CostType>
std::vector<Edge<CostType>> kruskal_heavy(const std::vector<std::vector<Edge<CostType>>> &graph) {
  int n = graph.size();
  std::vector<Edge<CostType>> edges;
  for (int i = 0; i < n; ++i) {
    for (const Edge<CostType> &e : graph[i]) edges.emplace_back(e);
  }
  std::sort(edges.begin(), edges.end());
  std::vector<Edge<CostType>> res;
  UnionFind uf(n);
  for (const Edge<CostType> &e : edges) {
    if (uf.unite(e.src, e.dst)) res.emplace_back(e);
  }
  return res;
}
