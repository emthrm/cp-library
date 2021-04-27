/*
 * @brief グラフ/二重辺連結成分分解 lowlink 版
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc039/tasks/arc039_d"

#include <iostream>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../graph/2-edge-connected_components_lowlink.hpp"
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
  TwoEdgeConnectedComponents<int> twcc(graph);
  LowestCommonAncestorByDoubling<int> lca(twcc.comp);
  lca.build();
  int q;
  std::cin >> q;
  while (q--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a; --b; --c;
    a = twcc.id[a];
    b = twcc.id[b];
    c = twcc.id[c];
    std::cout << (lca.distance(a, b) + lca.distance(b, c) == lca.distance(a, c) ? "OK\n" : "NG\n");
  }
  return 0;
}
