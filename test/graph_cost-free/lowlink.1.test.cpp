/*
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/lowlink.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<int>> graph(v);
  while (e--) {
    int s, t;
    std::cin >> s >> t;
    graph[s].emplace_back(t);
    graph[t].emplace_back(s);
  }
  emthrm::Lowlink l(graph);
  std::sort(l.bridges.begin(), l.bridges.end());
  for (const auto& [source, target] : l.bridges) {
    std::cout << source << ' ' << target << '\n';
  }
  return 0;
}
