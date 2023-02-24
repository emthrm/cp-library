/*
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/enumerate_bridges.hpp"

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
  std::vector<std::pair<int, int>> bridges = emthrm::enumerate_bridges(graph);
  std::sort(bridges.begin(), bridges.end());
  for (const auto& [source, target] : bridges) {
    std::cout << source << ' ' << target << '\n';
  }
  return 0;
}
