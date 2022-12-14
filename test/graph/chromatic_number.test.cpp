/*
 * @brief グラフ/彩色数
 */
#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include <iostream>
#include <vector>

#include "emthrm/graph/chromatic_number.hpp"
#include "emthrm/graph/edge.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<bool>>> graph(n);
  while (m--) {
    int u, v;
    std::cin >> u >> v;
    graph[u].emplace_back(u, v);
    graph[v].emplace_back(v, u);
  }
  std::cout << chromatic_number(graph) << '\n';
  return 0;
}
