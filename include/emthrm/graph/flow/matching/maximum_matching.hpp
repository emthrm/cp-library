/**
 * @brief 一般グラフの最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#ifndef EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_
#define EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_

#include <vector>

#include "emthrm/math/matrix/gauss_jordan.hpp"
#include "emthrm/math/matrix/matrix.hpp"
#include "emthrm/math/modint.hpp"
#include "emthrm/util/xorshift.hpp"

namespace emthrm {

int maximum_matching(const std::vector<std::vector<int>>& graph) {
  constexpr int P = 1000000007;
  using ModInt = MInt<P>;
  ModInt::set_mod(P);
  const int n = graph.size();
  Matrix<ModInt> tutte_matrix(n, n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int j : graph[i]) {
      if (j > i) {
        const ModInt x = xor128.rand(1, P);
        tutte_matrix[i][j] = x;
        tutte_matrix[j][i] = -x;
      }
    }
  }
  return gauss_jordan(&tutte_matrix, ModInt(0)) / 2;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_
