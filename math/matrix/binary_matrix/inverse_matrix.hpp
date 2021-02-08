/**
 * @brief 逆行列 バイナリ行列版
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#pragma once
#include <cassert>
#include <utility>
#include "binary_matrix.hpp"

template <int COL>
bool inverse(const BinaryMatrix<COL> &mat, BinaryMatrix<COL> &inv) {
  int n = mat.n;
  BinaryMatrix<COL> gauss_jordan(n, n << 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) gauss_jordan[i][j] = mat[i][j];
    gauss_jordan[i][n + i] = 1;
  }
  for (int col = 0; col < n; ++col) {
    int pivot = -1;
    for (int row = col; row < n; ++row) {
      if (gauss_jordan[row][col]) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) return false;
    std::swap(gauss_jordan[col], gauss_jordan[pivot]);
    for (int row = 0; row < n; ++row) {
      if (row != col && gauss_jordan[row][col]) gauss_jordan[row] ^= gauss_jordan[col];
    }
  }
  assert(inv.n == n && inv.m == n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) inv[i][j] = gauss_jordan[i][n + j];
  return true;
}
