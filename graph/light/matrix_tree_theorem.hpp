#pragma once
#include <vector>
#include "../../math/matrix/matrix.hpp"
#include "../../math/matrix/determinant.hpp"

template <typename T>
T matrix_tree_theorem(const std::vector<std::vector<int>> &graph, const T EPS) {
  const int n = graph.size();
  Matrix<int> laplacian(n, n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int j : graph[i]) {
      ++laplacian[i][i];
      --laplacian[i][j];
    }
  }
  Matrix<int> cofactor(n - 1, n - 1);
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      cofactor[i][j] = laplacian[i + 1][j + 1];
    }
  }
  return det(cofactor, EPS);
}
