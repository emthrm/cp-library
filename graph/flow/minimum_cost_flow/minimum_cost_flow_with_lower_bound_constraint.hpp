#pragma once
#include <limits>

template <template <typename, typename> class C, typename T, typename U>
struct MinimumCostFlowWithLowerBoundConstraint {
  const U uinf;

  explicit MinimumCostFlowWithLowerBoundConstraint(
      const int n, const U m, const U uinf = std::numeric_limits<U>::max())
      : uinf(uinf), m(m), sum_lb(0), mcf(n, uinf) {}

  void add_edge(const int src, const int dst, const T lb, const T ub,
                const U cost) {
    mcf.add_edge(src, dst, ub - lb, cost);
    mcf.add_edge(src, dst, lb, cost - m);
    sum_lb += lb;
  }

  U solve(const int s, const int t, const T flow) {
    const U tmp = mcf.solve(s, t, flow);
    return tmp == uinf ? uinf : tmp + m * sum_lb;
  }

private:
  const U m;
  T sum_lb;
  C<T, U> mcf;
};
