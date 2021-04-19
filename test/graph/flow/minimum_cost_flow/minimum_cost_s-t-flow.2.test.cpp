/*
 * @brief グラフ/フロー/最小費用流/最小費用 $s$-$t$-フロー 最短路反復法版 (solve(s, t))
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "../../../../graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp"

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
  int m = v.size();
  MinimumCostSTFlow<int, long long> mcf(n + m + 2);
  const int s = n + m, t = n + m + 1;
  for (int i = 0; i < n; ++i) {
    mcf.add_edge(s, i, 1, 0);
    mcf.add_edge(i, n + std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), a[i])), 1, -b[i]);
    mcf.add_edge(i, n + std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), b[i])), 1, -a[i]);
  }
  for (int i = 0; i < m; ++i) mcf.add_edge(n + i, t, 1, 0);
  std::cout << -mcf.solve(s, t) << '\n';
  return 0;
}
