#pragma once
#include <limits>

template <template <typename, typename> class C, typename T, typename U>
struct MinimumCostFlowWithMinimumFlowConstraint {
  const U uinf;

  MinimumCostFlowWithMinimumFlowConstraint(int n, const U M, const U uinf = std::numeric_limits<U>::max())
  : M(M), uinf(uinf), mcf(n, uinf) {}

  void add_edge(int src, int dst, T lb, T ub, U cost) {
    mcf.add_edge(src, dst, ub - lb, cost);
    mcf.add_edge(src, dst, lb, cost - M);
    lb_sum += lb;
  }

  U solve(int s, int t, T flow) {
    U tmp = mcf.solve(s, t, flow);
    return tmp == uinf ? uinf : tmp + M * lb_sum;
  }

private:
  const U M;
  T lb_sum = 0;
  C<T, U> mcf;
};
