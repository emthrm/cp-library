/*
 * @brief グラフ/lowlink (関節点)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <algorithm>
#include <iostream>
#include <vector>
#include "../../graph/edge.hpp"
#include "../../graph/lowlink.hpp"

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
  Lowlink<bool> low(graph);
  std::sort(low.ap.begin(), low.ap.end());
  for (int e : low.ap) std::cout << e << '\n';
  return 0;
}
