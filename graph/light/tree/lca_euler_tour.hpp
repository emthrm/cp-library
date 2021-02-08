#pragma once
#include <algorithm>
#include <utility>
#include <vector>
#include "euler_tour.hpp"
#include "../../../data_structure/sparse_table.hpp"

struct LCA : EulerTour {
  LCA(const std::vector<std::vector<int>> &graph, int root = 0) : EulerTour(graph, root) {
    int n = this->tour.size();
    std::vector<P> nodes(n);
    for (int i = 0; i < n; ++i) nodes[i] = {this->depth[i], this->tour[i]};
    st.init(nodes, [](P a, P b) -> P { return std::min(a, b); });
  }

  int query(int u, int v) const {
    u = this->left[u];
    v = this->left[v];
    if (u > v) std::swap(u, v);
    return st.query(u, v + 1).second;
  }

private:
  using P = std::pair<int, int>;

  SparseTable<P> st;
};
