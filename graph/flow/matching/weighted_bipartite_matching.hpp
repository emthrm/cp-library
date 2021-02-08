/**
 * @brief 二部グラフの重み付き最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <limits>
#include <vector>
#include "../minimum_cost_flow/primal_dual.hpp"

template <typename T>
struct WeightedBipartiteMatching {
  WeightedBipartiteMatching(int left, int right, T TINF) : left(left), right(right), pd(left + right + 2, std::numeric_limits<int>::max(), TINF) {}

  void add_edge(int src, int dst, T cost) { pd.add_edge(src, left + dst, 1, -cost); }

  T solve() {
    for (int i = 0; i < left; ++i) pd.add_edge(left + right, i, 1, 0);
    for (int i = 0; i < right; ++i) pd.add_edge(left + i, left + right + 1, 1, 0);
    return -pd.min_cost_max_flow(left + right, left + right + 1, left).second;
  }

  std::vector<int> matching() const {
    std::vector<int> res(left, -1);
    for (int i = 0; i < left; ++i) {
      for (auto e : pd.graph[i]) {
        if (e.cap == 0 && left <= e.dst && e.dst < left + right) {
          res[i] = e.dst - left;
          break;
        }
      }
    }
    return res;
  }

private:
  int left, right;
  PrimalDual<int, T> pd;
};
