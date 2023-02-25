#ifndef EMTHRM_MATH_MATRIX_BINARY_MATRIX_GAUSS_JORDAN_HPP_
#define EMTHRM_MATH_MATRIX_BINARY_MATRIX_GAUSS_JORDAN_HPP_

#include <utility>

#include "emthrm/math/matrix/binary_matrix/binary_matrix.hpp"

namespace emthrm {

template <bool IS_EXTENDED = false, int N>
int gauss_jordan(BinaryMatrix<N>* a) {
  const int m = a->nrow(), n = a->ncol();
  int rank = 0;
  for (int col = 0; col < (IS_EXTENDED ? n - 1 : n); ++col) {
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

}  // namespace emthrm

#endif  // EMTHRM_MATH_MATRIX_BINARY_MATRIX_GAUSS_JORDAN_HPP_
