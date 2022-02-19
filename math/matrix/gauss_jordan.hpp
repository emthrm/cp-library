#pragma once
#include <utility>

#include "./matrix.hpp"

template <typename T>
int gauss_jordan(Matrix<T>* a, const T eps = 1e-8,
                 const bool is_extended = false) {
  const int m = a->nrow(), n = a->ncol();
  int rank = 0;
  for (int col = 0; col < (is_extended ? n - 1 : n); ++col) {
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
