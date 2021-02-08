/**
 * @brief 行列木定理
 * @docs docs/graph/spectral_graph_theory.md
 */

#pragma once
#include <vector>
#include "edge.hpp"
#include "../math/matrix/matrix.hpp"
#include "../math/matrix/determinant.hpp"

template <typename T, typename CostType>
T matrix_tree_theorem(const std::vector<std::vector<Edge<CostType>>> &graph, const T EPS) {
  int n = graph.size();
  Matrix<int> laplacian(n, n, 0);
  for (int i = 0; i < n; ++i) for (const Edge<CostType> &e : graph[i]) {
    ++laplacian[e.src][e.src];
    --laplacian[e.src][e.dst];
  }
  Matrix<int> cofactor(n - 1, n - 1);
  for (int i = 0; i < n - 1; ++i) for (int j = 0; j < n - 1; ++j) cofactor[i][j] = laplacian[i + 1][j + 1];
  return det(cofactor, EPS);
}
