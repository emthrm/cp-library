#pragma once
// #include <algorithm>
#include <vector>

struct SCC {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, comp;

  SCC(const std::vector<std::vector<int>> &graph, bool heavy = false) : graph(graph), heavy(heavy) {
    n = graph.size();
    rev_graph.resize(n);
    for (int i = 0; i < n; ++i) for (int e : graph[i]) rev_graph[e].emplace_back(i);
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
    for (int i = 0; i < n; ++i) for (int e : graph[i]) {
      if (id[i] != id[e]) comp[id[i]].emplace_back(id[e]);
    }
    // if (heavy) {
    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }

private:
  bool heavy;
  int n;
  std::vector<std::vector<int>> graph, rev_graph;
  std::vector<bool> used;
  std::vector<int> order;

  void dfs(int ver) {
    used[ver] = true;
    for (int e : graph[ver]) {
      if (!used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    if (heavy) vertices[now].emplace_back(ver);
    for (int e : rev_graph[ver]) {
      if (id[e] == -1) rev_dfs(e, now);
    }
  }
};
