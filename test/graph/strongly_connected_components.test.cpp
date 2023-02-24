/*
 * @title グラフ/強連結成分分解
 */
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/strongly_connected_components.hpp"

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    graph[a].emplace_back(a, b);
  }
  const std::vector<std::vector<int>> ans =
      emthrm::StronglyConnectedComponents<bool, true>(graph).vertices;
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
