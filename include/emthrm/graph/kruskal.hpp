/**
 * @brief Kruskal 法
 * @docs docs/graph/minimum_spanning_tree.md
 */

#ifndef EMTHRM_GRAPH_KRUSKAL_HPP_
#define EMTHRM_GRAPH_KRUSKAL_HPP_

#include <algorithm>
#include <vector>

#include "emthrm/data_structure/union-find/union-find.hpp"
#include "emthrm/graph/edge.hpp"

namespace emthrm {

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

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_KRUSKAL_HPP_