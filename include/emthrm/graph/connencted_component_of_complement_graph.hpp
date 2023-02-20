#ifndef EMTHRM_GRAPH_CONNENCTED_COMPONENT_OF_COMPLEMENT_GRAPH_HPP_
#define EMTHRM_GRAPH_CONNENCTED_COMPONENT_OF_COMPLEMENT_GRAPH_HPP_

#include <ranges>
#include <vector>

#include "emthrm/data_structure/union-find/union-find.hpp"
#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType>
UnionFind connencted_component_of_complement_graph(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  UnionFind union_find(n);
  const auto check = [&graph, n, &union_find](const int ver) -> void {
    std::vector<bool> is_adjacent(n, false);
    for (const int e : graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      is_adjacent[e] = true;
    }
    for (int i = 0; i < n; ++i) {
      if (!is_adjacent[i]) union_find.unite(ver, i);
    }
  };
  int argmin_deg = 0;
  for (int i = 1; i < n; ++i) {
    if (graph[i].size() < graph[argmin_deg].size()) argmin_deg = i;
  }
  check(argmin_deg);
  for (const int e : graph[argmin_deg]
                   | std::views::transform(&Edge<CostType>::dst)) {
    check(e);
  }
  return union_find;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_CONNENCTED_COMPONENT_OF_COMPLEMENT_GRAPH_HPP_
