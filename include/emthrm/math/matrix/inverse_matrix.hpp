#pragma once
#include <algorithm>
#include <iterator>
#include <utility>

#include "emthrm/math/matrix/matrix.hpp"

template <typename T, typename U = double>
Matrix<U> inverse_matrix(const Matrix<T>& a, const U eps = 1e-8) {
  const int n = a.nrow();
  Matrix<U> b(n, n << 1, 0);
  for (int i = 0; i < n; ++i) {
    std::copy(a[i].begin(), a[i].end(), b[i].begin());
    b[i][n + i] = 1;
  }
  for (int col = 0; col < n; ++col) {
    int pivot = -1;
    U mx = eps;
    for (int row = col; row < n; ++row) {
      const U abs = (b[row][col] < 0 ? -b[row][col] : b[row][col]);
      if (abs > mx) {
        pivot = row;
        mx = abs;
      }
    }
    if (pivot == -1) return Matrix<U>(0, 0);
    std::swap(b[col], b[pivot]);
    U tmp = b[col][col];
    for (int col2 = 0; col2 < (n << 1); ++col2) {
      b[col][col2] /= tmp;
    }
    for (int row = 0; row < n; ++row) {
      if (row != col && (b[row][col] < 0 ? -b[row][col] : b[row][col]) > eps) {
        tmp = b[row][col];
        for (int col2 = 0; col2 < (n << 1); ++col2) {
          b[row][col2] -= b[col][col2] * tmp;
        }
      }
    }
  }
  Matrix<U> inv(n, n);
  for (int i = 0; i < n; ++i) {
    std::copy(std::next(b[i].begin(), n), b[i].end(), inv[i].begin());
  }
  return inv;
}
