/*
 * @brief グラフ/最短路問題/Bellman-Ford 法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>
#include <limits>
#include <vector>
#include "../../../graph/edge.hpp"
#include "../../../graph/shortest_path/bellman-ford.hpp"

int main() {
  constexpr long long LINF = std::numeric_limits<long long>::max();
  int v, e, r;
  std::cin >> v >> e >> r;
  std::vector<std::vector<Edge<long long>>> graph(v);
  for (int i = 0; i < e; ++i) {
    int s, t, d;
    std::cin >> s >> t >> d;
    graph[s].emplace_back(s, t, d);
  }
  BellmanFord<long long> bf(graph, LINF);
  if (bf.has_negative_cycle(r)) {
    std::cout << "NEGATIVE CYCLE\n";
    return 0;
  }
  for (int i = 0; i < v; ++i) {
    if (bf.dist[i] == LINF) {
      std::cout << "INF\n";
    } else {
      std::cout << bf.dist[i] << '\n';
    }
  }
  return 0;
}
