/**
 * @brief ガウス・ジョルダンの消去法 バイナリ行列版
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#pragma once
#include <utility>
#include "binary_matrix.hpp"

template <int COL>
int gauss_jordan(BinaryMatrix<COL> &mat, bool is_extended = false) {
  int rank = 0;
  for (int col = 0; col < mat.n; ++col) {
    if (is_extended && col == mat.n - 1) break;
    int pivot = -1;
    for (int row = rank; row < mat.m; ++row) {
      if (mat[row][col]) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) continue;
    std::swap(mat[rank], mat[pivot]);
    for (int row = 0; row < mat.m; ++row) {
      if (row != rank && mat[row][col]) mat[row] ^= mat[rank];
    }
    ++rank;
  }
  return rank;
}
