/*
 * @title グラフ/橋の列挙
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/enumerate_bridges.hpp"

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
  std::vector<emthrm::Edge<bool>> bridges = emthrm::enumerate_bridges(graph);
  std::ranges::sort(bridges.begin(), bridges.end(), {},
                    [](const emthrm::Edge<bool>& e) -> std::pair<int, int> {
                      return std::make_pair(e.src, e.dst);
                    });
  for (const emthrm::Edge<bool>& bridge : bridges) {
    std::cout << bridge.src << ' ' << bridge.dst << '\n';
  }
  return 0;
}
