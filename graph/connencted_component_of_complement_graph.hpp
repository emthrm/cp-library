#pragma once
#include <vector>
#include "edge.hpp"
#include "../data_structure/union-find/union-find.hpp"

template <typename CostType>
UnionFind connencted_component_of_complement_graph(const std::vector<std::vector<Edge<CostType>>> &graph) {
  int n = graph.size();
  UnionFind uf(n);
  auto check = [&graph, n, &uf](int ver) -> void {
    std::vector<bool> adj(n, false);
    for (const Edge<CostType> &e : graph[ver]) adj[e.dst] = true;
    for (int i = 0; i < n; ++i) {
      if (!adj[i]) uf.unite(ver, i);
    }
  };
  int argmin_deg = 0;
  for (int i = 1; i < n; ++i) {
    if (graph[i].size() < graph[argmin_deg].size()) argmin_deg = i;
  }
  check(argmin_deg);
  for (const Edge<CostType> &e : graph[argmin_deg]) check(e.dst);
  return uf;
}
