/*
 * @brief グラフ/lowlink (橋)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <algorithm>
#include <iostream>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/lowlink.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<Edge<bool>>> graph(v);
  while (e--) {
    int s, t;
    std::cin >> s >> t;
    graph[s].emplace_back(s, t);
    graph[t].emplace_back(t, s);
  }
  Lowlink<bool> l(graph);
  std::sort(l.bridges.begin(), l.bridges.end(),
            [](const Edge<bool>& a, const Edge<bool>& b) -> bool {
              return a.src != b.src ? a.src < b.src : a.dst < b.dst;
            });
  for (const Edge<bool>& bridge : l.bridges) {
    std::cout << bridge.src << ' ' << bridge.dst << '\n';
  }
  return 0;
}
