/*
 * @brief グラフ/二重辺連結成分分解 lowlink 版
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc039/tasks/arc039_d"

#include <iostream>
#include <vector>

#include "../../graph/2-edge-connected_components_by_lowlink.hpp"
#include "../../graph/edge.hpp"
#include "../../graph/tree/lowest_common_ancestor_by_doubling.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<int>>> graph(n);
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    graph[x].emplace_back(x, y, 1);
    graph[y].emplace_back(y, x, 1);
  }
  const TwoEdgeConnectedComponents<int> two_edge_connected_components(graph);
  LowestCommonAncestorByDoubling<int> lowest_common_ancestor(
      two_edge_connected_components.g);
  lowest_common_ancestor.build();
  int q;
  std::cin >> q;
  while (q--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a; --b; --c;
    a = two_edge_connected_components.id[a];
    b = two_edge_connected_components.id[b];
    c = two_edge_connected_components.id[c];
    std::cout << (lowest_common_ancestor.distance(a, b) +
                  lowest_common_ancestor.distance(b, c) ==
                  lowest_common_ancestor.distance(a, c) ?
                  "OK\n" : "NG\n");
  }
  return 0;
}
