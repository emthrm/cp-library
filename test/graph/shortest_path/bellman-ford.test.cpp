/*
 * @brief グラフ/最短路問題/Bellman-Ford 法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include <vector>

#include "../../../graph/edge.hpp"
#include "../../../graph/shortest_path/bellman-ford.hpp"

int main() {
  int v, e, r;
  std::cin >> v >> e >> r;
  std::vector<std::vector<Edge<long long>>> graph(v);
  while (e--) {
    int s, t, d;
    std::cin >> s >> t >> d;
    graph[s].emplace_back(s, t, d);
  }
  BellmanFord<long long> bellman_ford(graph);
  if (bellman_ford.has_negative_cycle(r)) {
    std::cout << "NEGATIVE CYCLE\n";
    return 0;
  }
  for (int i = 0; i < v; ++i) {
    if (bellman_ford.dist[i] == bellman_ford.inf) {
      std::cout << "INF\n";
    } else {
      std::cout << bellman_ford.dist[i] << '\n';
    }
  }
  return 0;
}
