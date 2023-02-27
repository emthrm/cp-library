/*
 * @title グラフ/木/HL 分解（最小共通祖先）
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
 */

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/tree/heavy-light_decomposition.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<emthrm::Edge<int>>> graph(n);
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    while (k--) {
      int c;
      std::cin >> c;
      graph[i].emplace_back(i, c, 1);
      graph[c].emplace_back(c, i, 1);
    }
  }
  const emthrm::HeavyLightDecomposition<int>
      heavy_light_decomposition(graph, 0);
  int q;
  std::cin >> q;
  while (q--) {
    int u, v;
    std::cin >> u >> v;
    std::cout << heavy_light_decomposition.lowest_common_ancestor(u, v) << '\n';
  }
  return 0;
}
