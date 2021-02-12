/*
 * @brief グラフ/フロー/最小費用流/主双対法 (minimum_cost_flow(s, t, flow))
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <iostream>
#include "../../../../graph/flow/minimum_cost_flow/primal_dual.hpp"

int main() {
  int v, e, f;
  std::cin >> v >> e >> f;
  PrimalDual<int, int> pd(v);
  while (e--) {
    int u, v, c, d;
    std::cin >> u >> v >> c >> d;
    pd.add_edge(u, v, c, d);
  }
  int ans = pd.minimum_cost_flow(0, v - 1, f);
  std::cout << (ans == pd.uinf ? -1 : ans) << '\n';
  return 0;
}
