/**
 * @brief 二重辺連結成分分解 いもす法版
 * @docs docs/graph/2-edge-connected_components.md
 */

#pragma once
// #include <algorithm>
#include <set>
#include <queue>
#include <utility>
#include <vector>
#include "edge.hpp"
#include "detect_bridge.hpp"

template <typename CostType>
struct TwoEdgeConnectedComponentsImos {
  std::vector<Edge<CostType>> bridge;
  std::vector<int> id;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> comp;

  TwoEdgeConnectedComponentsImos(const std::vector<std::vector<Edge<CostType>>> &graph, bool heavy = false) : bridge(detect_bridge(graph)) {
    int n = graph.size();
    id.assign(n, -1);
    std::set<std::pair<int, int>> st;
    for (const Edge<CostType> &e : bridge) {
      st.emplace(e.src, e.dst);
      st.emplace(e.dst, e.src);
    }
    int now = 0;
    std::queue<int> que;
    for (int i = 0; i < n; ++i) {
      if (id[i] != -1) continue;
      que.emplace(i);
      id[i] = now++;
      if (heavy) vertices.emplace_back(std::vector<int>{i});
      while (!que.empty()) {
        int ver = que.front(); que.pop();
        for (const Edge<CostType> &e : graph[ver]) {
          if (id[e.dst] == -1 && st.count({ver, e.dst}) == 0) {
            id[e.dst] = id[i];
            if (heavy) vertices[id[i]].emplace_back(e.dst);
            que.emplace(e.dst);
          }
        }
      }
    }
    comp.resize(now);
    for (const Edge<CostType> &e : bridge) {
      int u = id[e.src], v = id[e.dst];
      comp[u].emplace_back(u, v, e.cost);
      comp[v].emplace_back(v, u, e.cost);
    }
    // for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
  }
};
