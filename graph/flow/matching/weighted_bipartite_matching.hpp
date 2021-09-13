/**
 * @brief 二部グラフの重み付き最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <vector>
#include "../minimum_cost_flow/minimum_cost_s-t-flow.hpp"

template <typename T>
struct WeightedBipartiteMatching {
  WeightedBipartiteMatching(const int left, const int right)
  : left(left), right(right), mcf(left + right + 2) {}

  void add_edge(const int src, const int dst, const T cost) {
    mcf.add_edge(src, left + dst, 1, -cost);
  }

  T solve() {
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
    std::vector<int> res(left, -1);
    for (int i = 0; i < left; ++i) {
      for (const auto e : mcf.graph[i]) {
        if (e.cap == 0 && left <= e.dst && e.dst < left + right) {
          res[i] = e.dst - left;
          break;
        }
      }
    }
    return res;
  }

private:
  const int left, right;
  MinimumCostSTFlow<int, T> mcf;
};
