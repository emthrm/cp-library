/*
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/connected_components_of_complement_graph
 */

#include <iostream>
#include <ranges>
#include <vector>

#include "emthrm/data_structure/union-find/union-find.hpp"
#include "emthrm/graph_cost-free/connencted_component_of_complement_graph.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  emthrm::UnionFind union_find =
      emthrm::connencted_component_of_complement_graph(graph);
  int k = 0;
  std::vector<std::vector<int>> v(n);
  for (const int i : std::views::iota(0, n)) {
    v[union_find.root(i)].emplace_back(i);
    if (union_find.root(i) == i) ++k;
  }
  std::cout << k << '\n';
  for (const std::vector<int>& v_i : v) {
    if (v_i.empty()) continue;
    std::cout << v_i.size();
    for (const int v_ij : v_i) std::cout << ' ' << v_ij;
    std::cout << '\n';
  }
  return 0;
}
