/**
 * @brief 二重辺連結成分分解 lowlink 版
 * @docs docs/graph/2-edge-connected_components.md
 */

#pragma once
// #include <algorithm>
#include <vector>

#include "./edge.hpp"
#include "./lowlink.hpp"

template <typename CostType>
struct TwoEdgeConnectedComponents : Lowlink<CostType> {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> g;

  explicit TwoEdgeConnectedComponents(
      const std::vector<std::vector<Edge<CostType>>>& graph,
      const bool is_full_ver = false)
      : Lowlink<CostType>(graph), is_full_ver(is_full_ver) {
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
    // if (is_full_ver) {
    //   for (int i = 0; i < m; ++i) {
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    // }
  }

 private:
  const bool is_full_ver;

  void dfs(const int par, const int ver, int* m) {
    if (par != -1 && this->order[par] >= this->lowlink[ver]) {
      id[ver] = id[par];
    } else {
      id[ver] = (*m)++;
      if (is_full_ver) vertices.emplace_back();
    }
    if (is_full_ver) vertices[id[ver]].emplace_back(ver);
    for (const Edge<CostType>& e : this->graph[ver]) {
      if (id[e.dst] == -1) dfs(ver, e.dst, m);
    }
  }
};
