/**
 * @brief タットの定理
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <vector>
#include "../../../math/matrix/matrix.hpp"
#include "../../../math/matrix/gauss_jordan.hpp"
#include "../../../util/xorshift.hpp"

int tutte_theorem(const std::vector<std::vector<int>> &graph) {
  constexpr double EPS = 1e-8;
  int n = graph.size();
  Matrix<double> mat(n, n, 0);
  for (int i = 0; i < n; ++i) {
    for (int e : graph[i]) {
      if (e > i) {
        double x = 0;
        while (x < EPS) {
          int den = xor128.rand();
          if (den > EPS) x = 1.0 * xor128.rand() / den;
        }
        mat[i][e] = x;
        mat[e][i] = -x;
      }
    }
  }
  return gauss_jordan(mat, EPS) / 2;
}
