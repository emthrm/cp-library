#pragma once

template <template <typename, typename> class C, typename T, typename U>
struct MinimumCostFlowWithMinimumFlowConstraint {
  MinimumCostFlowWithMinimumFlowConstraint(int n, const U M, const T TINF, const U UINF) : M(M), UINF(UINF), pd(n, TINF, UINF) {}

  void add_edge(int src, int dst, T lb, T ub, U cost) {
    pd.add_edge(src, dst, ub - lb, cost);
    pd.add_edge(src, dst, lb, cost - M);
    lb_sum += lb;
  }

  U solve(int s, int t, T flow) {
    U tmp = pd.minimum_cost_flow(s, t, flow);
    return tmp == UINF ? UINF : tmp + M * lb_sum;
  }

private:
  const U M, UINF;
  T lb_sum = 0;
  C<T, U> pd;
};
