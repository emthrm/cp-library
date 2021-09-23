/*
 * @brief グラフ/オイラー路 無向グラフ版
 */
#define PROBLEM "https://yukicoder.me/problems/no/583"

#include <iostream>
#include "../../graph/eulerian_trail_in_undirected_graph.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  EulerianTrailInUndirectedGraph eulerian_trail(n);
  while (m--) {
    int sa, sb;
    std::cin >> sa >> sb;
    eulerian_trail.add_edge(sa, sb);
  }
  std::cout << (eulerian_trail.build() ? "YES\n" : "NO\n");
  return 0;
}
