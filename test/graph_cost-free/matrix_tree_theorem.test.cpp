/*
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/counting_spanning_tree_undirected
 */

#include <iostream>
#include <vector>

#include "emthrm/graph_cost-free/matrix_tree_theorem.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int u, v;
    std::cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  std::cout << emthrm::matrix_tree_theorem(graph, ModInt()) << '\n';
  return 0;
}
