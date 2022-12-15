#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#include "emthrm/graph/cost-free/lowlink.hpp"

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
  std::sort(
      l.bridges.begin(), l.bridges.end(),
      [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool {
        int source_a, target_a, source_b, target_b;
        std::tie(source_a, target_a) = a;
        std::tie(source_b, target_b) = b;
        return source_a != source_b ? source_a < source_b : target_a < target_b;
      });
  for (const std::pair<int, int>& bridge : l.bridges) {
    std::cout << bridge.first << ' ' << bridge.second << '\n';
  }
  return 0;
}
