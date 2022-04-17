/**
 * @brief 多項式補間
 * @docs docs/math/lagrange_interpolation.md
 */

#pragma once
#include <functional>
#include <vector>

#include "./multipoint_evaluation.hpp"

template <template <typename> class C, typename T>
C<T> polynomial_interpolation(const std::vector<T>& x,
                              const std::vector<T>& y) {
  MultipointEvaluation<C, T> m(x);
  m.build(m.subproduct_tree[1].differential());
  const int n = x.size();
  const std::function<C<T>(int)> f = [&y, &m, n, &f](const int node) -> C<T> {
    return node >= n ? C<T>{y[node - n] / m.f_x[node - n]} :
                       f(node << 1) * m.subproduct_tree[(node << 1) + 1]
                       + f((node << 1) + 1) * m.subproduct_tree[node << 1];
  };
  return f(1);
}
