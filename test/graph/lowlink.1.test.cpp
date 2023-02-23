/*
 * @brief グラフ/lowlink (橋)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/lowlink.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<emthrm::Edge<bool>>> graph(v);
  while (e--) {
    int s, t;
    std::cin >> s >> t;
    graph[s].emplace_back(s, t);
    graph[t].emplace_back(t, s);
  }
  emthrm::Lowlink<bool> l(graph);
  std::ranges::sort(l.bridges.begin(), l.bridges.end(), {},
                    [](const emthrm::Edge<bool>& e) -> std::pair<int, int> {
                      return std::make_pair(e.src, e.dst);
                    });
  for (const emthrm::Edge<bool>& bridge : l.bridges) {
    std::cout << bridge.src << ' ' << bridge.dst << '\n';
  }
  return 0;
}
