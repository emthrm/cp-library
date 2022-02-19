#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

#include "./gauss_jordan.hpp"
#include "./matrix.hpp"

template <typename T, typename U = double>
std::vector<U> linear_equation(const Matrix<T>& a, const std::vector<T>& b,
                               const U eps = 1e-8) {
  const int m = a.nrow(), n = a.ncol();
  Matrix<U> c(m, n + 1);
  for (int i = 0; i < m; ++i) {
    std::copy(a[i].begin(), a[i].end(), c[i].begin());
    c[i].back() = b[i];
  }
  const int rank = gauss_jordan(&c, eps, true);
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
