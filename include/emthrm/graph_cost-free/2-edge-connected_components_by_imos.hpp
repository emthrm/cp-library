#ifndef EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_
#define EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_

#include <algorithm>
#include <set>
#include <queue>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/enumerate_bridges.hpp"

namespace emthrm {

template <bool IS_FULL_VER = false>
struct TwoEdgeConnectedComponentsByImos {
  std::vector<int> id;
  std::vector<std::pair<int, int>> bridge;
  std::vector<std::vector<int>> vertices, g;

  explicit TwoEdgeConnectedComponentsByImos(
      const std::vector<std::vector<int>>& graph)
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
      if constexpr (IS_FULL_VER) vertices.emplace_back(std::vector<int>{i});
      while (!que.empty()) {
        const int ver = que.front();
        que.pop();
        for (const int e : graph[ver]) {
          if (id[e] == -1 && !st.contains(std::minmax(ver, e))) {
            id[e] = id[i];
            if constexpr (IS_FULL_VER) vertices.back().emplace_back(e);
            que.emplace(e);
          }
        }
      }
    }
    g.resize(m);
    for (const auto& [s, t] : bridge) {
      const int u = id[s], v = id[t];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    // for (int i = 0; i < m; ++i) {
    //   std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_
