/*
 * @title グラフ/フロー/最大流/最小流量制約付き最大流
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615"

#include <iostream>
#include <vector>

#include "emthrm/graph/flow/maximum_flow/dinic.hpp"
#include "emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp"

int main() {
  while (true) {
    int n, m;
    std::cin >> n >> m;
    if (n == 0 && m == 0) [[unlikely]] break;
    std::vector<int> u(m), v(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> u[i] >> v[i];
      --u[i]; --v[i];
    }
    const int s = m + n, t = m + n + 1;
    const auto solve =
        [m, n, s, t, &u, &v](const int lb, const int ub) -> bool {
          emthrm::MaximumFlowWithLowerBoundConstraint<emthrm::Dinic, int>
              lower_bound_constraint(m + n + 2);
          for (int i = 0; i < m; ++i) {
            lower_bound_constraint.add_edge(s, i, 1, 1);
          }
          for (int i = 0; i < n; ++i) {
            lower_bound_constraint.add_edge(m + i, t, lb, ub);
          }
          for (int i = 0; i < m; ++i) {
            lower_bound_constraint.add_edge(i, m + u[i], 0, 1);
            lower_bound_constraint.add_edge(i, m + v[i], 0, 1);
          }
          return lower_bound_constraint.solve(s, t) != -1;
        };
    int lb = 0, ub = n;
    for (int i = 0, j = 1; i < n; ++i) {
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
