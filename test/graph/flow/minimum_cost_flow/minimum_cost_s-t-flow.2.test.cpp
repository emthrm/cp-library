/*
 * @title グラフ/フロー/最小費用流/最小費用 $s$-$t$-フロー 最短路反復法版 (solve(s, t))
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), v;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
    v.emplace_back(a[i]);
    v.emplace_back(b[i]);
  }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  const int m = v.size();
  for (int i = 0; i < n; ++i) {
    a[i] = std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), a[i]));
    b[i] = std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), b[i]));
  }
  emthrm::MinimumCostSTFlow<int, long long> minimum_cost_flow(n + m + 2);
  const int s = n + m, t = n + m + 1;
  for (int i = 0; i < n; ++i) {
    minimum_cost_flow.add_edge(s, i, 1, 0);
    minimum_cost_flow.add_edge(i, n + a[i], 1, -v[b[i]]);
    minimum_cost_flow.add_edge(i, n + b[i], 1, -v[a[i]]);
  }
  for (int i = 0; i < m; ++i) {
    minimum_cost_flow.add_edge(n + i, t, 1, 0);
  }
  std::cout << -minimum_cost_flow.solve(s, t) << '\n';
  return 0;
}
