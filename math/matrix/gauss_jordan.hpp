#pragma once
#include <cmath>
#include <utility>
#include "matrix.hpp"

template <typename T>
int gauss_jordan(Matrix<T> &mat, const T EPS = 1e-8, bool is_extended = false) {
  int m = mat.height(), n = mat.width(), rank = 0;
  for (int col = 0; col < n; ++col) {
    if (is_extended && col == n - 1) break;
    int pivot = -1;
    T mx = EPS;
    for (int row = rank; row < m; ++row) {
      if (std::abs(mat[row][col]) > mx) {
        pivot = row;
        mx = std::abs(mat[row][col]);
      }
    }
    if (pivot == -1) continue;
    std::swap(mat[rank], mat[pivot]);
    T tmp = mat[rank][col];
    for (int col2 = 0; col2 < n; ++col2) mat[rank][col2] /= tmp;
    for (int row = 0; row < m; ++row) {
      if (row != rank && std::abs(mat[row][col]) > EPS) {
        tmp = mat[row][col];
        for (int col2 = 0; col2 < n; ++col2) mat[row][col2] -= mat[rank][col2] * tmp;
      }
    }
    ++rank;
  }
  return rank;
}
