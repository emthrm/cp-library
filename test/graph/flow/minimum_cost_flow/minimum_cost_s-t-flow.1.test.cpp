/*
 * @title グラフ/フロー/最小費用流/最小費用 $s$-$t$-フロー 最短路反復法版
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
 */

#include <iostream>

#include "emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp"

int main() {
  int v, e, f;
  std::cin >> v >> e >> f;
  emthrm::MinimumCostSTFlow<int, int> minimum_cost_flow(v);
  while (e--) {
    int u, v, c, d;
    std::cin >> u >> v >> c >> d;
    minimum_cost_flow.add_edge(u, v, c, d);
  }
  const int ans = minimum_cost_flow.solve(0, v - 1, f);
  std::cout << (ans == minimum_cost_flow.uinf ? -1 : ans) << '\n';
  return 0;
}
