#pragma once
#include <vector>

#include "emthrm/data_structure/union-find/union-find.hpp"
#include "emthrm/graph/edge.hpp"

template <typename CostType>
UnionFind connencted_component_of_complement_graph(
    const std::vector<std::vector<Edge<CostType>>>& graph) {
  const int n = graph.size();
  UnionFind union_find(n);
  const auto check = [&graph, n, &union_find](const int ver) -> void {
    std::vector<bool> is_adjacent(n, false);
    for (const Edge<CostType>& e : graph[ver]) is_adjacent[e.dst] = true;
    for (int i = 0; i < n; ++i) {
      if (!is_adjacent[i]) union_find.unite(ver, i);
    }
  };
  int argmin_deg = 0;
  for (int i = 1; i < n; ++i) {
    if (graph[i].size() < graph[argmin_deg].size()) argmin_deg = i;
  }
  check(argmin_deg);
  for (const Edge<CostType>& e : graph[argmin_deg]) check(e.dst);
  return union_find;
}
