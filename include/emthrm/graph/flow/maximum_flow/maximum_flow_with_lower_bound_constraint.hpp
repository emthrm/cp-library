#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_
#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_

#include "emthrm/graph/flow/maximum_flow/maximum_flow.hpp"

namespace emthrm {

template <template <typename> class C, typename T>
requires MaximumFlow<C, T>
struct MaximumFlowWithLowerBoundConstraint {
  explicit MaximumFlowWithLowerBoundConstraint(const int n)
      : n(n), sum_lb(0), mf(n + 2) {}

  void add_edge(const int src, const int dst, const T lb, const T ub) {
    mf.add_edge(src, dst, ub - lb);
    mf.add_edge(n, dst, lb);
    mf.add_edge(src, n + 1, lb);
    sum_lb += lb;
  }

  T solve(const int s, const int t) {
    const T a = mf.maximum_flow(n, n + 1);
    const T b = mf.maximum_flow(s, n + 1);
    const T c = mf.maximum_flow(n, t);
    const T d = mf.maximum_flow(s, t);
    return a + b == sum_lb && b == c ? b + d : -1;
  }

 private:
  const int n;
  T sum_lb;
  C<T> mf;
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_
