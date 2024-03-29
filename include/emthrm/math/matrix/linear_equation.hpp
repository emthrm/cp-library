#ifndef EMTHRM_MATH_MATRIX_LINEAR_EQUATION_HPP_
#define EMTHRM_MATH_MATRIX_LINEAR_EQUATION_HPP_

#include <algorithm>
#include <cmath>
#include <vector>

#include "emthrm/math/matrix/gauss_jordan.hpp"
#include "emthrm/math/matrix/matrix.hpp"

namespace emthrm {

template <typename T, typename U = double>
std::vector<U> linear_equation(const Matrix<T>& a, const std::vector<T>& b,
                               const U eps = 1e-8) {
  const int m = a.nrow(), n = a.ncol();
  Matrix<U> c(m, n + 1);
  for (int i = 0; i < m; ++i) {
    std::copy(a[i].begin(), a[i].end(), c[i].begin());
    c[i].back() = b[i];
  }
  const int rank = gauss_jordan<true>(&c, eps);
  for (int row = rank; row < m; ++row) {
    if ((c[row].back() < 0 ? -c[row].back() : c[row].back()) > eps) {
      return std::vector<U>{};
    }
  }
  std::vector<U> res(n, 0);
  for (int i = 0, j = 0; i < rank; ++i) {
    while ((c[i][j] < 0 ? -c[i][j] : c[i][j]) <= eps) ++j;
    res[j++] = c[i].back();
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_MATRIX_LINEAR_EQUATION_HPP_
