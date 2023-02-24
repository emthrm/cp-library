/*
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/arc039/tasks/arc039_d
 */

#include <iostream>
#include <vector>

#include "emthrm/graph_cost-free/2-edge-connected_components_by_lowlink.hpp"
#include "emthrm/graph_cost-free/tree/lowest_common_ancestor_by_doubling.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  const emthrm::TwoEdgeConnectedComponents two_edge_connected_components(graph);
  emthrm::LowestCommonAncestorByDoubling lca(two_edge_connected_components.g);
  lca.build();
  int q;
  std::cin >> q;
  while (q--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a; --b; --c;
    a = two_edge_connected_components.id[a];
    b = two_edge_connected_components.id[b];
    c = two_edge_connected_components.id[c];
    if (lca.distance(a, b) + lca.distance(b, c) == lca.distance(a, c)) {
      std::cout << "OK\n";
    } else {
      std::cout << "NG\n";
    }
  }
  return 0;
}
