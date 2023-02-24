/*
 * @title グラフ/フロー/最小費用流/最小流量制約付き最小費用流
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230
 */

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp"
#include "emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp"

int main() {
  constexpr int INF = std::numeric_limits<int>::max();
  int n, m;
  std::cin >> n >> m;
  emthrm::MinimumCostFlowWithLowerBoundConstraint<
      emthrm::MinimumCostBFlow, long long, long long>
          lower_bound_constraint(n, INF);
  std::vector<std::vector<emthrm::Edge<int>>> graph(n);
  while (m--) {
    int x, y, s;
    std::cin >> x >> y >> s;
    lower_bound_constraint.add_edge(y, x, 1, INF, -s);
    graph[x].emplace_back(x, y, s);
  }
  std::vector<long long> dp(n, 0);
  for (int i = n - 2; i >= 0; --i) {
    for (const emthrm::Edge<int>& e : graph[i]) {
      dp[i] = std::max(dp[i], dp[e.dst] + e.cost);
    }
  }
  lower_bound_constraint.add_edge(0, n - 1, 0, INF, dp[0]);
  std::cout << lower_bound_constraint.solve(0, 0, 0) << '\n';
  return 0;
}
