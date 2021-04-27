/**
 * @brief 多項式補間
 * @docs docs/math/lagrange_interpolation.md
 */

#pragma once
#include <functional>
#include <vector>
#include "multipoint_evaluation.hpp"

template <template <typename> class C, typename T>
C<T> polynomial_interpolation(const std::vector<T> &x, const std::vector<T> &y) {
  MultipointEvaluation<C, T> multieval(x);
  multieval.calc(multieval.node[1].differential());
  int n = x.size();
  std::function<C<T>(int)> calc = [&](int pos) {
    if (pos >= n) return C<T>{y[pos - n] / multieval.val[pos - n]};
    return calc(pos << 1) * multieval.node[(pos << 1) + 1] + calc((pos << 1) + 1) * multieval.node[pos << 1];
  };
  return calc(1);
}
