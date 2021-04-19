/**
 * @brief 二部グラフの重み付き最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <vector>
#include "../minimum_cost_flow/minimum_cost_s-t-flow.hpp"

template <typename T>
struct WeightedBipartiteMatching {
  WeightedBipartiteMatching(int left, int right) : left(left), right(right), mcf(left + right + 2) {}

  void add_edge(int src, int dst, T cost) { mcf.add_edge(src, left + dst, 1, -cost); }

  T solve() {
    for (int i = 0; i < left; ++i) mcf.add_edge(left + right, i, 1, 0);
    for (int i = 0; i < right; ++i) mcf.add_edge(left + i, left + right + 1, 1, 0);
    return -mcf.minimum_cost_maximum_flow(left + right, left + right + 1, left).second;
  }

  std::vector<int> matching() const {
    std::vector<int> res(left, -1);
    for (int i = 0; i < left; ++i) {
      for (auto e : mcf.graph[i]) {
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
  MinimumCostSTFlow<int, T> mcf;
};
