/**
 * @title 多項式補間
 * @docs docs/math/lagrange_interpolation.md
 */

#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_POLYNOMIAL_INTERPOLATION_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_POLYNOMIAL_INTERPOLATION_HPP_

#include <vector>

#include "emthrm/math/formal_power_series/multipoint_evaluation.hpp"

namespace emthrm {

template <template <typename> class C, typename T>
C<T> polynomial_interpolation(const std::vector<T>& x,
                              const std::vector<T>& y) {
  MultipointEvaluation<C, T> m(x);
  m.build(m.subproduct_tree[1].differential());
  const int n = x.size();
  const auto f = [&y, &m, n](auto f, const int node) -> C<T> {
    return node >= n ? C<T>{y[node - n] / m.f_x[node - n]} :
                       f(f, node << 1) * m.subproduct_tree[(node << 1) + 1]
                       + f(f, (node << 1) + 1) * m.subproduct_tree[node << 1];
  };
  return f(f, 1);
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_POLYNOMIAL_INTERPOLATION_HPP_
