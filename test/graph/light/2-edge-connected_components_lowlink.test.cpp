#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc039/tasks/arc039_d"

#include <iostream>
#include <vector>
#include "../../../graph/light/2-edge-connected_components_lowlink.hpp"
#include "../../../graph/light/tree/lca_doubling.hpp"

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
  TwoEdgeConnectedComponents twcc(graph);
  LCADoubling lca(twcc.comp);
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
