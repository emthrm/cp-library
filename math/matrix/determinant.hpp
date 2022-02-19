#pragma once
#include <algorithm>
#include <utility>

#include "./matrix.hpp"

template <typename T, typename U>
U det(const Matrix<T>& a, const U eps) {
  const int n = a.nrow();
  Matrix<U> b(n, n);
  for (int i = 0; i < n; ++i) {
    std::copy(a[i].begin(), a[i].end(), b[i].begin());
  }
  U res = 1;
  for (int j = 0; j < n; ++j) {
    int pivot = -1;
    U mx = eps;
    for (int i = j; i < n; ++i) {
      const U abs = (b[i][j] < 0 ? -b[i][j] : b[i][j]);
      if (abs > mx) {
        pivot = i;
        mx = abs;
      }
    }
    if (pivot == -1) return 0;
    if (pivot != j) {
      std::swap(b[j], b[pivot]);
      res = -res;
    }
    res *= b[j][j];
    for (int k = j + 1; k < n; ++k) {
      b[j][k] /= b[j][j];
    }
    for (int i = j + 1; i < n; ++i) {
      for (int k = j + 1; k < n; ++k) {
        b[i][k] -= b[i][j] * b[j][k];
      }
    }
  }
  return res;
}
