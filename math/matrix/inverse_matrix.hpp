#pragma once
#include <cassert>
#include <cmath>
#include <utility>
#include "matrix.hpp"

template <typename T, typename U = double>
bool inverse(const Matrix<T> &mat, Matrix<U> &inv, const U EPS = 1e-8) {
  int n = mat.height();
  Matrix<U> gauss_jordan(n, n << 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) gauss_jordan[i][j] = mat[i][j];
    gauss_jordan[i][n + i] = 1;
  }
  for (int col = 0; col < n; ++col) {
    int pivot = -1;
    U mx = EPS;
    for (int row = col; row < n; ++row) {
      if (std::abs(gauss_jordan[row][col]) > mx) {
        pivot = row;
        mx = std::abs(gauss_jordan[row][col]);
      }
    }
    if (pivot == -1) return false;
    std::swap(gauss_jordan[col], gauss_jordan[pivot]);
    U tmp = gauss_jordan[col][col];
    for (int col2 = 0; col2 < (n << 1); ++col2) gauss_jordan[col][col2] /= tmp;
    for (int row = 0; row < n; ++row) {
      if (row != col && std::abs(gauss_jordan[row][col]) > EPS) {
        tmp = gauss_jordan[row][col];
        for (int col2 = 0; col2 < (n << 1); ++col2) gauss_jordan[row][col2] -= gauss_jordan[col][col2] * tmp;
      }
    }
  }
  assert(inv.height() == n && inv.width() == n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) inv[i][j] = gauss_jordan[i][n + j];
  return true;
}
