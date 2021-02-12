/*
 * @brief グラフ/フロー/最小費用流/主双対法 (minimum_cost_flow(s, t))
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "../../../../graph/flow/minimum_cost_flow/primal_dual.hpp"

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
  PrimalDual<int, long long> pd(n + m + 2);
  const int s = n + m, t = n + m + 1;
  for (int i = 0; i < n; ++i) {
    pd.add_edge(s, i, 1, 0);
    pd.add_edge(i, n + std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), a[i])), 1, -b[i]);
    pd.add_edge(i, n + std::distance(v.begin(), std::lower_bound(v.begin(), v.end(), b[i])), 1, -a[i]);
  }
  for (int i = 0; i < m; ++i) pd.add_edge(n + i, t, 1, 0);
  std::cout << -pd.minimum_cost_flow(s, t) << '\n';
  return 0;
}
