/*
 * @title グラフ/Kruskal 法
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
 */

#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/kruskal.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<emthrm::Edge<long long>>> edge(v);
  for (int i = 0; i < e; ++i) {
    int s, t, w;
    std::cin >> s >> t >> w;
    edge[s].emplace_back(s, t, w);
    edge[t].emplace_back(t, s, w);
  }
  std::cout << emthrm::kruskal(edge) << '\n';
  return 0;
}
