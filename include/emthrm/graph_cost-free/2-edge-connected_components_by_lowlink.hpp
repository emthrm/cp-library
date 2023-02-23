#ifndef EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_
#define EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_

// #include <algorithm>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/lowlink.hpp"

namespace emthrm {

template <bool IS_FULL_VER = false>
struct TwoEdgeConnectedComponents : Lowlink {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, g;

  explicit TwoEdgeConnectedComponents(
      const std::vector<std::vector<int>>& graph)
      : Lowlink(graph) {
    const int n = graph.size();
    id.assign(n, -1);
    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (id[i] == -1) dfs(-1, i, &m);
    }
    g.resize(m);
    for (const auto& [s, t] : this->bridges) {
      const int u = id[s], v = id[t];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    // if constexpr (IS_FULL_VER) {
    //   for (int i = 0; i < m; ++i) {
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    // }
  }

 private:
  void dfs(const int par, const int ver, int* m) {
    if (par != -1 && this->order[par] >= this->lowlink[ver]) {
      id[ver] = id[par];
    } else {
      id[ver] = (*m)++;
      if constexpr (IS_FULL_VER) vertices.emplace_back();
    }
    if constexpr (IS_FULL_VER) vertices[id[ver]].emplace_back(ver);
    for (const int e : this->graph[ver]) {
      if (id[e] == -1) dfs(ver, e, m);
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_
