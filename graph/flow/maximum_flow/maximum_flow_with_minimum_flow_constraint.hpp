#pragma once

template <template <typename> class C, typename T>
struct MaximumFlowWithMinimumFlowConstraint {
  MaximumFlowWithMinimumFlowConstraint(int n) : n(n), flow(n + 2) {}

  void add_edge(int src, int dst, T lb, T ub) {
    flow.add_edge(src, dst, ub - lb);
    flow.add_edge(n, dst, lb);
    flow.add_edge(src, n + 1, lb);
    lb_sum += lb;
  }

  T solve(int s, int t, T limit) {
    T a = flow.maximum_flow(n, n + 1, limit);
    T b = flow.maximum_flow(s, n + 1, limit);
    T c = flow.maximum_flow(n, t, limit);
    T d = flow.maximum_flow(s, t, limit);
    return a + b == lb_sum && b == c ? b + d : T(-1);
  }

private:
  int n;
  C<T> flow;
  T lb_sum = 0;
};
