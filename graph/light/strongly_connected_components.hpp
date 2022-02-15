#pragma once
// #include <algorithm>
#include <vector>

struct StronglyConnectedComponents {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, g;

  StronglyConnectedComponents(const std::vector<std::vector<int>>& graph,
                              const bool is_full_ver = false)
      : is_full_ver(is_full_ver), n(graph.size()), is_used(n, false),
        graph(graph), rgraph(n) {
    order.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (!is_used[i]) dfs(i);
    }
    id.assign(n, -1);
    for (int i = 0; i < n; ++i) {
      for (const int e : graph[i]) rgraph[e].emplace_back(i);
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
      for (const int e : graph[i]) {
        if (id[i] != id[e]) g[id[i]].emplace_back(id[e]);
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
  std::vector<std::vector<int>> graph, rgraph;

  void dfs(const int ver) {
    is_used[ver] = true;
    for (const int e : graph[ver]) {
      if (!is_used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rdfs(const int ver, const int m) {
    id[ver] = m;
    if (is_full_ver) vertices.back().emplace_back(ver);
    for (const int e : rgraph[ver]) {
      if (id[e] == -1) rdfs(e, m);
    }
  }
};
