#pragma once
// #include <algorithm>
#include <set>
#include <queue>
#include <utility>
#include <vector>
#include "detect_bridge.hpp"

struct TwoEdgeConnectedComponentsImos {
  std::vector<std::pair<int, int>> bridge;
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, comp;

  TwoEdgeConnectedComponentsImos(const std::vector<std::vector<int>> &graph, bool heavy = false) : bridge(detect_bridge(graph)) {
    int n = graph.size();
    id.assign(n, -1);
    std::set<std::pair<int, int>> st;
    for (const std::pair<int, int> &e : bridge) {
      st.emplace(e.first, e.second);
      st.emplace(e.second, e.first);
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
        for (int e : graph[ver]) {
          if (id[e] == -1 && st.count({ver, e}) == 0) {
            id[e] = id[i];
            if (heavy) vertices[id[i]].emplace_back(e);
            que.emplace(e);
          }
        }
      }
    }
    comp.resize(now);
    for (const std::pair<int, int> &e : bridge) {
      int u = id[e.first], v = id[e.second];
      comp[u].emplace_back(v);
      comp[v].emplace_back(u);
    }
    // for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
  }
};
