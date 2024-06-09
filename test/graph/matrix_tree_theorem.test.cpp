/*
 * @title グラフ/行列木定理
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/counting_spanning_tree_undirected
 */

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/matrix_tree_theorem.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);
  while (m--) {
    int u, v;
    std::cin >> u >> v;
    graph[u].emplace_back(u, v);
    graph[v].emplace_back(v, u);
  }
  std::cout << emthrm::matrix_tree_theorem(graph, ModInt()) << '\n';
  return 0;
}
