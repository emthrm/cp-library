/*
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc291/tasks/abc291_h
 */

#include <iostream>
#include <vector>

#include "emthrm/graph_cost-free/tree/centroid_decomposition.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  const std::vector<int> p = emthrm::CentroidDecomposition(graph).parent;
  for (int i = 0; i < n; ++i) {
    std::cout << (p[i] == -1 ? -1 : p[i] + 1) << " \n"[i + 1 == n];
  }
  return 0;
}
