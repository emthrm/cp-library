#ifndef EMTHRM_MATH_MATRIX_BINARY_MATRIX_INVERSE_MATRIX_HPP_
#define EMTHRM_MATH_MATRIX_BINARY_MATRIX_INVERSE_MATRIX_HPP_

#include <cassert>
#include <utility>

#include "emthrm/math/matrix/binary_matrix/binary_matrix.hpp"

namespace emthrm {

template <int N>
BinaryMatrix<N> inverse_matrix(const BinaryMatrix<N>& a) {
  const int n = a.nrow();
  BinaryMatrix<N> b(n, n << 1, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = a[i][j];
    }
    b[i][n + i] = 1;
  }
  for (int col = 0; col < n; ++col) {
    int pivot = -1;
    for (int row = col; row < n; ++row) {
      if (b[row][col]) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) return BinaryMatrix<N>(0, 0);
    std::swap(b[col], b[pivot]);
    for (int row = 0; row < n; ++row) {
      if (row != col && b[row][col]) b[row] ^= b[col];
    }
  }
  BinaryMatrix<N> inv(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      inv[i][j] = b[i][n + j];
    }
  }
  return inv;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_MATRIX_BINARY_MATRIX_INVERSE_MATRIX_HPP_
