/**
 * @brief 二重辺連結成分分解 lowlink 版
 * @docs docs/graph/2-edge-connected_components.md
 */

#ifndef EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_
#define EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_

// #include <algorithm>
#include <ranges>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/lowlink.hpp"

namespace emthrm {

template <typename CostType, bool IS_FULL_VER = false>
struct TwoEdgeConnectedComponents : Lowlink<CostType> {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> g;

  explicit TwoEdgeConnectedComponents(
      const std::vector<std::vector<Edge<CostType>>>& graph)
      : Lowlink<CostType>(graph) {
    const int n = graph.size();
    id.assign(n, -1);
    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (id[i] == -1) dfs(-1, i, &m);
    }
    g.resize(m);
    for (const Edge<CostType>& e : this->bridges) {
      const int u = id[e.src], v = id[e.dst];
      g[u].emplace_back(u, v, e.cost);
      g[v].emplace_back(v, u, e.cost);
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
    for (const int e : this->graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (id[e] == -1) dfs(ver, e, m);
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_
