/*
 * @title グラフ/内周
 *
 * verification-helper: PROBLEM https://yukicoder.me/problems/no/1320
 */

#include <iostream>
#include <limits>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/girth_in_directed_graph.hpp"
#include "emthrm/graph/girth_in_undirected_graph.hpp"

int main() {
  constexpr long long LINF = std::numeric_limits<long long>::max();
  int t, n, m;
  std::cin >> t >> n >> m;
  if (t == 0) {
    std::vector<emthrm::Edge<long long>> edges;
    while (m--) {
      int u, v, w;
      std::cin >> u >> v >> w;
      --u; --v;
      edges.emplace_back(u, v, w);
    }
    const long long ans = emthrm::girth_in_undirected_graph(n, edges, LINF);
    std::cout << (ans == LINF ? -1 : ans) << '\n';
  } else if (t == 1) {
    std::vector<std::vector<emthrm::Edge<long long>>> graph(n);
    while (m--) {
      int u, v, w;
      std::cin >> u >> v >> w;
      --u; --v;
      graph[u].emplace_back(u, v, w);
    }
    const long long ans = emthrm::girth_in_directed_graph(graph, LINF);
    std::cout << (ans == LINF ? -1 : ans) << '\n';
  }
  return 0;
}
