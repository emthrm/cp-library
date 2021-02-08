/*
 * @brief グラフ/木/double sweep
 */
#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include <vector>
#include "../../../graph/edge.hpp"
#include "../../../graph/tree/double_sweep.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<Edge<long long>>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph[a].emplace_back(a, b, c);
    graph[b].emplace_back(b, a, c);
  }
  DoubleSweep<long long> ds(graph);
  ds.build_path();
  int y = ds.path.size();
  std::cout << ds.diameter << ' ' << y << '\n';
  for (int i = 0; i < y; ++i) std::cout << ds.path[i] << " \n"[i + 1 == y];
  return 0;
}
