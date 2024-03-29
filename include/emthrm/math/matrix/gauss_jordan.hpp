#ifndef EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_
#define EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_

#include <utility>

#include "emthrm/math/matrix/matrix.hpp"

namespace emthrm {

template <bool IS_EXTENDED = false, typename T>
int gauss_jordan(Matrix<T>* a, const T eps = 1e-8) {
  const int m = a->nrow(), n = a->ncol();
  int rank = 0;
  for (int col = 0; col < (IS_EXTENDED ? n - 1 : n); ++col) {
    int pivot = -1;
    T mx = eps;
    for (int row = rank; row < m; ++row) {
      const T abs = ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col]);
      if (abs > mx) {
        pivot = row;
        mx = abs;
      }
    }
    if (pivot == -1) continue;
    std::swap((*a)[rank], (*a)[pivot]);
    T tmp = (*a)[rank][col];
    for (int col2 = 0; col2 < n; ++col2) {
      (*a)[rank][col2] /= tmp;
    }
    for (int row = 0; row < m; ++row) {
      if (row != rank &&
          ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col]) > eps) {
        tmp = (*a)[row][col];
        for (int col2 = 0; col2 < n; ++col2) {
          (*a)[row][col2] -= (*a)[rank][col2] * tmp;
        }
      }
    }
    ++rank;
  }
  return rank;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_
