/*
 * @title グラフ/木/double sweep
 */
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/tree/double_sweep.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<emthrm::Edge<long long>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph[a].emplace_back(a, b, c);
    graph[b].emplace_back(b, a, c);
  }
  const auto [x, u] = emthrm::double_sweep(graph);
  const int y = u.size();
  std::cout << x << ' ' << y << '\n';
  for (int i = 0; i < y; ++i) {
    std::cout << u[i] << " \n"[i + 1 == y];
  }
  return 0;
}
