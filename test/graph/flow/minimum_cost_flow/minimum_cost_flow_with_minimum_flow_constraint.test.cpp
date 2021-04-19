/*
 * @brief グラフ/フロー/最小費用流/最小流量制約付き最小費用流
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230"

#include <iostream>
#include <limits>
#include <vector>
#include "../../../../graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp"
#include "../../../../graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp"
#include "../../../../graph/edge.hpp"

int main() {
  constexpr int INF = std::numeric_limits<int>::max();
  int n, m;
  std::cin >> n >> m;
  MinimumCostFlowWithMinimumFlowConstraint<MinimumCostBFlow, long long, long long> pd(n, INF);
  std::vector<std::vector<Edge<int>>> graph(n);
  while (m--) {
    int x, y, s;
    std::cin >> x >> y >> s;
    pd.add_edge(y, x, 1, INF, -s);
    graph[x].emplace_back(x, y, s);
  }
  std::vector<long long> dp(n, 0);
  for (int i = n - 2; i >= 0; --i) {
    for (const Edge<int> &e : graph[i]) {
      if (dp[e.dst] + e.cost > dp[i]) dp[i] = dp[e.dst] + e.cost;
    }
  }
  pd.add_edge(0, n - 1, 0, INF, dp[0]);
  std::cout << pd.solve(0, 0, 0) << '\n';
  return 0;
}
