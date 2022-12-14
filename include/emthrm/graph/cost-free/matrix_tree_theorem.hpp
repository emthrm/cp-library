#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

#include "emthrm/math/matrix/determinant.hpp"
#include "emthrm/math/matrix/matrix.hpp"

template <typename T>
T matrix_tree_theorem(const std::vector<std::vector<int>>& graph,
                      const T eps = 1e-8) {
  const int n = graph.size();
  if (n == 1) return 1;
  Matrix<int> laplacian(n, n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int j : graph[i]) {
      ++laplacian[i][i];
      --laplacian[i][j];
    }
  }
  Matrix<int> cofactor(n - 1, n - 1);
  for (int i = 0; i < n - 1; ++i) {
    std::copy(std::next(laplacian[i + 1].begin()), laplacian[i + 1].end(),
              cofactor[i].begin());
  }
  return det(cofactor, eps);
}
