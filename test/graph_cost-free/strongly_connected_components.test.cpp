/*
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/scc
 */

#include <iostream>
#include <vector>

#include "emthrm/graph_cost-free/strongly_connected_components.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(b);
  }
  const std::vector<std::vector<int>> ans =
      emthrm::StronglyConnectedComponents<true>(graph).vertices;
  const int k = ans.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    const int l = ans[i].size();
    std::cout << l << ' ';
    for (int j = 0; j < l; ++j) {
      std::cout << ans[i][j] << " \n"[j + 1 == l];
    }
  }
  return 0;
}
