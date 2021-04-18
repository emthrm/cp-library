#pragma once
// #include <algorithm>
#include <vector>
#include "edge.hpp"

template <typename CostType>
struct StronglyConnectedComponents {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices;
  std::vector<std::vector<Edge<CostType>>> comp;

  StronglyConnectedComponents(const std::vector<std::vector<Edge<CostType>>> &graph, bool heavy = false) : graph(graph), heavy(heavy) {
    n = graph.size();
    rev_graph.resize(n);
    for (int i = 0; i < n; ++i) for (const Edge<CostType> &e : graph[i]) {
      rev_graph[e.dst].emplace_back(e.dst, e.src, e.cost);
    }
    used.assign(n, false);
    id.assign(n, -1);
    for (int i = 0; i < n; ++i) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (id[order[i]] == -1) {
        if (heavy) vertices.emplace_back();
        rev_dfs(order[i], now++);
      }
    }
    comp.resize(now);
    for (int i = 0; i < n; ++i) for (const Edge<CostType> &e : graph[i]) {
      if (id[i] != id[e.dst]) comp[id[i]].emplace_back(id[i], id[e.dst], e.cost);
    }
    // if (heavy) {
    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }

private:
  bool heavy;
  int n;
  std::vector<std::vector<Edge<CostType>>> graph, rev_graph;
  std::vector<bool> used;
  std::vector<int> order;

  void dfs(int ver) {
    used[ver] = true;
    for (const Edge<CostType> &e : graph[ver]) {
      if (!used[e.dst]) dfs(e.dst);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    if (heavy) vertices[now].emplace_back(ver);
    for (const Edge<CostType> &e : rev_graph[ver]) {
      if (id[e.dst] == -1) rev_dfs(e.dst, now);
    }
  }
};
