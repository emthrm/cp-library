/*
 * @brief グラフ/フロー/最大流/最小流量制約付き最大流
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615"

#include <iostream>
#include <vector>
#include "../../../../graph/flow/maximum_flow/dinic.hpp"
#include "../../../../graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp"

int main() {
  while (true) {
    int n, m;
    std::cin >> n >> m;
    if (n == 0 && m == 0) break;
    std::vector<int> u(m), v(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> u[i] >> v[i];
      --u[i]; --v[i];
    }
    const int s = m + n, t = m + n + 1;
    auto solve = [&](int lb, int ub) -> bool {
      MaximumFlowWithMinimumFlowConstraint<Dinic, int> mfmfc(m + n + 2);
      for (int i = 0; i < m; ++i) mfmfc.add_edge(s, i, 1, 1);
      for (int i = 0; i < n; ++i) mfmfc.add_edge(m + i, t, lb, ub);
      for (int i = 0; i < m; ++i) {
        mfmfc.add_edge(i, m + u[i], 0, 1);
        mfmfc.add_edge(i, m + v[i], 0, 1);
      }
      return mfmfc.solve(s, t, m) != -1;
    };
    int lb = 0, ub = n, j = 1;
    for (int i = 0; i < n; ++i) {
      while (j <= n && !solve(i, j)) ++j;
      if (j > n) break;
      if (ub - lb >= j - i) {
        lb = i;
        ub = j;
      }
      if (i == j) ++j;
    }
    std::cout << lb << ' ' << ub << '\n';
  }
  return 0;
}
