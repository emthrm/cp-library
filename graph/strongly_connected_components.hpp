#pragma once
// #include <algorithm>
#include <vector>

#include "./edge.hpp"

template <typename CostType>
struct StronglyConnectedComponents {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> g;

  explicit StronglyConnectedComponents(
      const std::vector<std::vector<Edge<CostType>>>& graph,
      const bool is_full_ver = false)
      : is_full_ver(is_full_ver), n(graph.size()), is_used(n, false),
        graph(graph), rgraph(n) {
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
        if (is_full_ver) vertices.emplace_back();
        rdfs(order[i], m++);
      }
    }
    g.resize(m);
    for (int i = 0; i < n; ++i) {
      for (const Edge<CostType>& e : graph[i]) {
        if (id[i] != id[e.dst]) g[id[i]].emplace_back(id[i], id[e.dst], e.cost);
      }
    }
    // if (is_full_ver) {
    //   for (int i = 0; i < m; ++i) {
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    // }
  }

 private:
  const bool is_full_ver;
  const int n;
  std::vector<bool> is_used;
  std::vector<int> order;
  const std::vector<std::vector<Edge<CostType>>> graph;
  std::vector<std::vector<Edge<CostType>>> rgraph;

  void dfs(const int ver) {
    is_used[ver] = true;
    for (const Edge<CostType>& e : graph[ver]) {
      if (!is_used[e.dst]) dfs(e.dst);
    }
    order.emplace_back(ver);
  }

  void rdfs(const int ver, const int m) {
    id[ver] = m;
    if (is_full_ver) vertices.back().emplace_back(ver);
    for (const Edge<CostType>& e : rgraph[ver]) {
      if (id[e.dst] == -1) rdfs(e.dst, m);
    }
  }
};
