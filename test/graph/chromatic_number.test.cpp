/*
 * @title グラフ/彩色数
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/chromatic_number
 */

#include <iostream>
#include <vector>

#include "emthrm/graph/chromatic_number.hpp"
#include "emthrm/graph/edge.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);
  while (m--) {
    int u, v;
    std::cin >> u >> v;
    graph[u].emplace_back(u, v);
    graph[v].emplace_back(v, u);
  }
  std::cout << emthrm::chromatic_number(graph) << '\n';
  return 0;
}
