#pragma once
#include <cmath>
#include <utility>
#include "matrix.hpp"

template <typename T, typename U>
U det(const Matrix<T> &mat, const U EPS) {
  int n = mat.height();
  Matrix<U> tmp(n, n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) tmp[i][j] = mat[i][j];
  U res = 1;
  for (int j = 0; j < n; ++j) {
    int pivot = -1;
    U mx = EPS;
    for (int i = j; i < n; ++i) {
      if (std::abs(tmp[i][j]) > mx) {
        pivot = i;
        mx = std::abs(tmp[i][j]);
      }
    }
    if (pivot == -1) return 0;
    if (pivot != j) {
      std::swap(tmp[j], tmp[pivot]);
      res = -res;
    }
    res *= tmp[j][j];
    for (int k = j + 1; k < n; ++k) tmp[j][k] /= tmp[j][j];
    for (int i = j + 1; i < n; ++i) for (int k = j + 1; k < n; ++k) {
      tmp[i][k] -= tmp[i][j] * tmp[j][k];
    }
  }
  return res;
}
