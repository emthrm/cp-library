/*
 * @brief グラフ/区間に辺を張るテク
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/786/B"

#include <iostream>
#include <vector>

#include "../../graph/noshi_graph.hpp"
#include "../../graph/shortest_path/dijkstra.hpp"

int main() {
  int n, q, s;
  std::cin >> n >> q >> s;
  --s;
  NoshiGraph<long long> graph(n);
  while (q--) {
    int t, v;
    std::cin >> t >> v;
    --v;
    if (t == 1) {
      int u, w;
      std::cin >> u >> w;
      --u;
      graph.add_edge(v, u, w);
    } else {
      int l, r, w;
      std::cin >> l >> r >> w;
      --l; --r;
      if (t == 2) {
        graph.add_edge(v, v + 1, l, r + 1, w);
      } else if (t == 3) {
        graph.add_edge(l, r + 1, v, v + 1, w);
      }
    }
  }
  Dijkstra<long long> dijkstra(graph.graph);
  const std::vector<long long> ans = dijkstra.build(s);
  for (int i = 0; i < n; ++i) {
    std::cout << (ans[i] == dijkstra.inf ? -1 : ans[i]) << " \n"[i + 1 == n];
  }
  return 0;
}
