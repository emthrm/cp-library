#ifndef EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_
#define EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_

#include <algorithm>
#include <set>
#include <queue>
#include <ranges>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/enumerate_bridges.hpp"

namespace emthrm {

template <typename CostType, bool IS_FULL_VER = false>
struct TwoEdgeConnectedComponentsByImos {
  std::vector<int> id;
  std::vector<Edge<CostType>> bridge;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> g;

  explicit TwoEdgeConnectedComponentsByImos(
      const std::vector<std::vector<Edge<CostType>>>& graph)
      : bridge(enumerate_bridges(graph)) {
    const int n = graph.size();
    id.assign(n, -1);
    std::set<std::pair<int, int>> st;
    for (const Edge<CostType>& e : bridge) st.emplace(e.src, e.dst);
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
        for (const int e : graph[ver]
                         | std::views::transform(&Edge<CostType>::dst)) {
          if (id[e] == -1 && !st.contains(std::minmax(ver, e))) {
            id[e] = id[i];
            if constexpr (IS_FULL_VER) vertices.back().emplace_back(e);
            que.emplace(e);
          }
        }
      }
    }
    g.resize(m);
    for (const Edge<CostType>& e : bridge) {
      const int u = id[e.src], v = id[e.dst];
      g[u].emplace_back(u, v, e.cost);
      g[v].emplace_back(v, u, e.cost);
    }
    if constexpr (IS_FULL_VER) {
      for (int i = 0; i < m; ++i) {
        std::sort(vertices[i].begin(), vertices[i].end());
      }
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_2_EDGE_CONNECTED_COMPONENTS_BY_IMOS_HPP_
