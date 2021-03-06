#pragma once
#include <cmath>
#include <vector>
#include "matrix.hpp"
#include "gauss_jordan.hpp"

template <typename T, typename U = double>
std::vector<U> linear_equation(const Matrix<T> &a, const std::vector<T> &b, const U EPS = 1e-8) {
  int m = a.height(), n = a.width();
  Matrix<U> matrix(m, n + 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) matrix[i][j] = a[i][j];
    matrix[i][n] = b[i];
  }
  int rank = gauss_jordan(matrix, EPS, true);
  for (int row = rank; row < m; ++row) {
    if (std::abs(matrix[row][n]) > EPS) return std::vector<U>();
  }
  std::vector<U> res(n, 0);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (std::abs(matrix[i][j]) < EPS) ++j;
    res[j++] = matrix[i][n];
  }
  return res;
}
