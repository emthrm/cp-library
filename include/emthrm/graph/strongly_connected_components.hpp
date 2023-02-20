#ifndef EMTHRM_GRAPH_STRONGLY_CONNECTED_COMPONENTS_HPP_
#define EMTHRM_GRAPH_STRONGLY_CONNECTED_COMPONENTS_HPP_

// #include <algorithm>
#include <ranges>
#include <vector>

#include "emthrm/graph/edge.hpp"

namespace emthrm {

template <typename CostType, bool IS_FULL_VER = false>
struct StronglyConnectedComponents {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> g;

  explicit StronglyConnectedComponents(
      const std::vector<std::vector<Edge<CostType>>>& graph)
      : n(graph.size()), is_used(n, false), graph(graph), rgraph(n) {
    for (int i = 0; i < n; ++i) {
      if (!is_used[i]) dfs(i);
    }
    id.assign(n, -1);
    order.reserve(n);
    for (int i = 0; i < n; ++i) {
      for (const Edge<CostType>& e : graph[i]) {
        rgraph[e.dst].emplace_back(e.dst, e.src, e.cost);
      }
    }
    int m = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (id[order[i]] == -1) {
        if constexpr (IS_FULL_VER) vertices.emplace_back();
        rdfs(order[i], m++);
      }
    }
    g.resize(m);
    for (int i = 0; i < n; ++i) {
      for (const Edge<CostType>& e : graph[i]) {
        if (id[i] != id[e.dst]) g[id[i]].emplace_back(id[i], id[e.dst], e.cost);
      }
    }
    // if constexpr (IS_FULL_VER) {
    //   for (int i = 0; i < m; ++i) {
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    // }
  }

 private:
  const int n;
  std::vector<bool> is_used;
  std::vector<int> order;
  const std::vector<std::vector<Edge<CostType>>> graph;
  std::vector<std::vector<Edge<CostType>>> rgraph;

  void dfs(const int ver) {
    is_used[ver] = true;
    for (const int e : graph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (!is_used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rdfs(const int ver, const int m) {
    id[ver] = m;
    if constexpr (IS_FULL_VER) vertices.back().emplace_back(ver);
    for (const int e : rgraph[ver]
                     | std::views::transform(&Edge<CostType>::dst)) {
      if (id[e] == -1) rdfs(e, m);
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_STRONGLY_CONNECTED_COMPONENTS_HPP_
