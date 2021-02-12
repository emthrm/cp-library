/*
 * @brief グラフ/巡回セールスマン問題
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>
#include <limits>
#include <vector>
#include "../../graph/tsp.hpp"

int main() {
  constexpr int INF = std::numeric_limits<int>::max();
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<Edge<int>>> g(v);
  while (e--) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g[s].emplace_back(s, t, d);
  }
  int ans = tsp(g, INF);
  std::cout << (ans == INF ? -1 : ans) << '\n';
  return 0;
}
