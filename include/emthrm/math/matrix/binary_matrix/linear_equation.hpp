/**
 * @brief 連立一次方程式 バイナリ行列版
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#pragma once
#include <vector>

#include "./binary_matrix.hpp"
#include "./gauss_jordan.hpp"

template <int N>
std::vector<bool> linear_equation(const BinaryMatrix<N>& a,
                                  const std::vector<bool>& b) {
  const int m = a.nrow(), n = a.ncol();
  BinaryMatrix<N> c(m, n + 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i][j] = a[i][j];
    }
    c[i][n] = b[i];
  }
  const int rank = gauss_jordan(&c, true);
  for (int row = rank; row < m; ++row) {
    if (c[row][n]) return std::vector<bool>{};
  }
  std::vector<bool> res(n, false);
  for (int i = 0, j = -1; i < rank; ++i) {
    j = (i == 0 ? c[i]._Find_first() : c[i]._Find_next(j));
    res[j] = c[i][n];
  }
  return res;
}
