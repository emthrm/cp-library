#pragma once
#include <algorithm>
#include <utility>
#include <vector>

#include "../../../data_structure/sparse_table.hpp"
#include "./euler_tour.hpp"

struct LowestCommonAncestor : EulerTour {
  explicit LowestCommonAncestor(const std::vector<std::vector<int>>& graph,
                                const int root = 0)
      : EulerTour(graph, root) {
    const int n = this->tour.size();
    std::vector<std::pair<int, int>> nodes(n);
    for (int i = 0; i < n; ++i) {
      nodes[i] = {this->depth[i], this->tour[i]};
    }
    sparse_table.init(
        nodes,
        [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            -> std::pair<int, int> {
          return std::min(a, b);
        });
  }

  int query(int u, int v) const {
    u = this->left[u];
    v = this->left[v];
    if (u > v) std::swap(u, v);
    return sparse_table.query(u, v + 1).second;
  }

 private:
  SparseTable<std::pair<int, int>> sparse_table;
};
