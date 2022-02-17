/**
 * @brief ガウス・ジョルダンの消去法 バイナリ行列版
 * @docs docs/math/matrix/binary_matrix/binary_matrix.md
 */

#pragma once
#include <utility>

#include "binary_matrix.hpp"

template <int N>
int gauss_jordan(BinaryMatrix<N>* a, const bool is_extended = false) {
  const int m = a->nrow(), n = a->ncol();
  int rank = 0;
  for (int col = 0; col < (is_extended ? n - 1 : n); ++col) {
    int pivot = -1;
    for (int row = rank; row < m; ++row) {
      if ((*a)[row][col]) {
        pivot = row;
        break;
      }
    }
    if (pivot == -1) continue;
    std::swap((*a)[rank], (*a)[pivot]);
    for (int row = 0; row < m; ++row) {
      if (row != rank && (*a)[row][col]) (*a)[row] ^= (*a)[rank];
    }
    ++rank;
  }
  return rank;
}
