#pragma once
#include <algorithm>
#include <set>
#include <queue>
#include <utility>
#include <vector>

#include "./enumerate_bridges.hpp"

struct TwoEdgeConnectedComponentsByImos {
  std::vector<int> id;
  std::vector<std::pair<int, int>> bridge;
  std::vector<std::vector<int>> vertices, g;

  explicit TwoEdgeConnectedComponentsByImos(
      const std::vector<std::vector<int>>& graph,
      const bool is_full_ver = false)
      : bridge(enumerate_bridges(graph)) {
    const int n = graph.size();
    id.assign(n, -1);
    const std::set<std::pair<int, int>> st(bridge.begin(), bridge.end());
    int m = 0;
    std::queue<int> que;
    for (int i = 0; i < n; ++i) {
      if (id[i] != -1) continue;
      que.emplace(i);
      id[i] = m++;
      if (is_full_ver) vertices.emplace_back(std::vector<int>{i});
      while (!que.empty()) {
        const int ver = que.front();
        que.pop();
        for (const int e : graph[ver]) {
          if (id[e] == -1 && !st.count(std::minmax(ver, e))) {
            id[e] = id[i];
            if (is_full_ver) vertices.back().emplace_back(e);
            que.emplace(e);
          }
        }
      }
    }
    g.resize(m);
    for (const std::pair<int, int>& e : bridge) {
      const int u = id[e.first], v = id[e.second];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    // for (int i = 0; i < m; ++i) {
    //   std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }
};
