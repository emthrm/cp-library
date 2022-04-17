/**
 * @brief 二部グラフの重み付き最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <cassert>
#include <vector>

#include "../minimum_cost_flow/minimum_cost_s-t-flow.hpp"

template <typename T>
struct WeightedBipartiteMatching {
  explicit WeightedBipartiteMatching(const int left, const int right)
      : is_built(false), left(left), right(right), mcf(left + right + 2) {}

  void add_edge(const int src, const int dst, const T cost) {
    mcf.add_edge(src, left + dst, 1, -cost);
  }

  T solve() {
    assert(!is_built);
    is_built = true;
    const int s = left + right, t = left + right + 1;
    for (int i = 0; i < left; ++i) {
      mcf.add_edge(s, i, 1, 0);
    }
    for (int i = 0; i < right; ++i) {
      mcf.add_edge(left + i, t, 1, 0);
    }
    return -mcf.minimum_cost_maximum_flow(s, t, left).second;
  }

  std::vector<int> matching() const {
    assert(is_built);
    std::vector<int> res(left, -1);
    for (int i = 0; i < left; ++i) {
      for (const auto& e : mcf.graph[i]) {
        if (e.cap == 0 && left <= e.dst && e.dst < left + right) {
          res[i] = e.dst - left;
          break;
        }
      }
    }
    return res;
  }

 private:
  bool is_built;
  const int left, right;
  MinimumCostSTFlow<int, T> mcf;
};
