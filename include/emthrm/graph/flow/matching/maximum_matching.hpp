#ifndef EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_
#define EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_

#include <random>
#include <vector>

#include "emthrm/math/matrix/gauss_jordan.hpp"
#include "emthrm/math/matrix/matrix.hpp"
#include "emthrm/math/modint.hpp"

namespace emthrm {

int maximum_matching(const std::vector<std::vector<int>>& graph) {
  constexpr unsigned int P = 1000000007;
  using ModInt = MInt<P>;
  ModInt::set_mod(P);
  static std::mt19937_64 engine(std::random_device {} ());
  static std::uniform_int_distribution<> dist(1, P - 1);
  const int n = graph.size();
  Matrix<ModInt> tutte_matrix(n, n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int j : graph[i]) {
      if (j > i) {
        const ModInt x = ModInt::raw(dist(engine));
        tutte_matrix[i][j] = x;
        tutte_matrix[j][i] = -x;
      }
    }
  }
  return gauss_jordan(&tutte_matrix, ModInt(0)) / 2;
}

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_FLOW_MATCHING_MAXIMUM_MATCHING_HPP_
