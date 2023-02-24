/**
 * @title 行列木定理
 * @docs docs/graph/spectral_graph_theory.md
 */

#ifndef EMTHRM_GRAPH_MATRIX_TREE_THEOREM_HPP_
#define EMTHRM_GRAPH_MATRIX_TREE_THEOREM_HPP_

#include <algorithm>
#include <iterator>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/math/matrix/determinant.hpp"
#include "emthrm/math/matrix/matrix.hpp"

namespace emthrm {

template <typename T, typename CostType>
T matrix_tree_theorem(const std::vector<std::vector<Edge<CostType>>>& graph,
                      const T eps = 1e-8) {
  const int n = graph.size();
  if (n == 1) [[unlikely]] return 1;
  Matrix<int> laplacian(n, n, 0);
  for (int i = 0; i < n; ++i) {
    for (const Edge<CostType>& e : graph[i]) {
      ++laplacian[e.src][e.src];
      --laplacian[e.src][e.dst];
    }
  }
  Matrix<int> cofactor(n - 1, n - 1);
  for (int i = 0; i < n - 1; ++i) {
    std::copy(std::next(laplacian[i + 1].begin()), laplacian[i + 1].end(),
              cofactor[i].begin());
  }
  return det(cofactor, eps);
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_MATRIX_TREE_THEOREM_HPP_
