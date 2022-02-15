/*
 * @brief グラフ/トポロジカルソート
 */
#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include <iostream>
#include <vector>

#include "../../graph/edge.hpp"
#include "../../graph/topological_sort.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<Edge<bool>>> graph(v);
  while (e--) {
    int s, t;
    std::cin >> s >> t;
    graph[s].emplace_back(s, t);
  }
  for (const int ans : topological_sort(graph)) std::cout << ans << '\n';
  return 0;
}
