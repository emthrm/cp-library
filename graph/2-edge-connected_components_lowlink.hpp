/**
 * @brief 二重辺連結成分分解 lowlink 版
 * @docs docs/graph/2-edge-connected_components.md
 */

#pragma once
// #include <algorithm>
#include <vector>
#include "lowlink.hpp"
#include "edge.hpp"

template <typename CostType>
struct TwoEdgeConnectedComponents : Lowlink<CostType> {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> comp;

  TwoEdgeConnectedComponents(const std::vector<std::vector<Edge<CostType>>> &graph, bool heavy = false) : Lowlink<CostType>(graph), heavy(heavy) {
    int n = graph.size();
    id.assign(n, -1);
    int now = 0;
    for (int i = 0; i < n; ++i) {
      if (id[i] == -1) dfs(-1, i, now);
    }
    comp.resize(now);
    for (const Edge<CostType> &e : this->bridge) {
      int u = id[e.src], v = id[e.dst];
      comp[u].emplace_back(u, v, e.cost);
      comp[v].emplace_back(v, u, e.cost);
    }
    // if (heavy) {
    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }

private:
  bool heavy;

  void dfs(int par, int ver, int &now) {
    if (par != -1 && this->order[par] >= this->lowlink[ver]) {
      id[ver] = id[par];
    } else {
      id[ver] = now++;
      if (heavy) vertices.emplace_back();
    }
    if (heavy) vertices[id[ver]].emplace_back(ver);
    for (const Edge<CostType> &e : this->graph[ver]) {
      if (id[e.dst] == -1) dfs(ver, e.dst, now);
    }
  }
};
