/*
 * @brief グラフ/最短路問題/Dijkstra 法
 */
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <iostream>
#include <vector>
#include "../../../graph/edge.hpp"
#include "../../../graph/shortest_path/dijkstra.hpp"

int main() {
  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  std::vector<std::vector<Edge<long long>>> graph(n);
  while (m--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph[a].emplace_back(a, b, c);
  }
  Dijkstra<long long> dij(graph);
  long long x = dij.build(s)[t];
  if (x == dij.inf) {
    std::cout << "-1\n";
    return 0;
  }
  std::vector<int> path = dij.build_path(t);
  int y = static_cast<int>(path.size()) - 1;
  std::cout << x << ' ' << y << '\n';
  for (int i = 0; i < y; ++i) std::cout << path[i] << ' ' << path[i + 1] << '\n';
  return 0;
}
