/*
 * @title グラフ/最短路問題/Dijkstra 法
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/shortest_path
 */

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/shortest_path/dijkstra.hpp"

int main() {
  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  std::vector<std::vector<emthrm::Edge<long long>>> graph(n);
  while (m--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph[a].emplace_back(a, b, c);
  }
  emthrm::Dijkstra<long long> dijkstra(graph);
  const long long x = dijkstra.build(s)[t];
  if (x == dijkstra.inf) {
    std::cout << "-1\n";
    return 0;
  }
  const std::vector<int> path = dijkstra.build_path(t);
  const int y = path.size() - 1;
  std::cout << x << ' ' << y << '\n';
  for (int i = 0; i < y; ++i) {
    std::cout << path[i] << ' ' << path[i + 1] << '\n';
  }
  return 0;
}
