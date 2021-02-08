/**
 * @brief 連立一次方程式 バイナリ行列版
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#pragma once
#include <vector>
#include "binary_matrix.hpp"
#include "gauss_jordan.hpp"

template <int COL>
std::vector<int> linear_equation(const BinaryMatrix<COL> &a, const std::vector<int> &b) {
  BinaryMatrix<COL> mat(a.m, a.n + 1);
  for (int i = 0; i < a.m; ++i) {
    for (int j = 0; j < a.n; ++j) mat[i][j] = a[i][j];
    mat[i][a.n] = b[i];
  }
  int rank = gauss_jordan(mat, true);
  std::vector<int> res;
  for (int row = rank; row < a.m; ++row) {
    if (mat[row][a.n]) return res;
  }
  res.assign(a.n, 0);
  for (int i = 0; i < rank; ++i) res[i] = mat[i][a.n];
  return res;
}
