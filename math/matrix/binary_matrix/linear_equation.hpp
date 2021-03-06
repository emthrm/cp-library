/**
 * @brief 連立一次方程式 バイナリ行列版
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#pragma once
#include <vector>
#include "binary_matrix.hpp"
#include "gauss_jordan.hpp"

template <int Col>
std::vector<bool> linear_equation(const BinaryMatrix<Col> &a, const std::vector<bool> &b) {
  BinaryMatrix<Col> mat(a.m, a.n + 1);
  for (int i = 0; i < a.m; ++i) {
    for (int j = 0; j < a.n; ++j) mat[i][j] = a[i][j];
    mat[i][a.n] = b[i];
  }
  int rank = gauss_jordan(mat, true);
  for (int row = rank; row < a.m; ++row) {
    if (mat[row][a.n]) return std::vector<bool>();
  }
  std::vector<bool> res(a.n, false);
  for (int i = 0, j; i < rank; ++i) {
    j = (i == 0 ? mat[i]._Find_first() : mat[i]._Find_next(j));
    res[j] = mat[i][a.n];
  }
  return res;
}
