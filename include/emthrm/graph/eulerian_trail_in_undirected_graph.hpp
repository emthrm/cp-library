/**
 * @brief オイラー路 無向グラフ版
 * @docs docs/graph/eulerian_trail.md
 */

#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

struct EulerianTrailInUndirectedGraph {
  std::vector<int> trail;

  explicit EulerianTrailInUndirectedGraph(const int n)
      : n(n), is_visited(n), graph(n) {}

  void add_edge(const int u, const int v) {
    graph[u].emplace_back(v, graph[v].size());
    graph[v].emplace_back(u, graph[u].size() - 1);
  }

  bool build(int s = -1) {
    trail.clear();
    int odd_deg = 0, edge_num = 0;
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() & 1) {
        ++odd_deg;
        if (s == -1) s = i;
      }
      edge_num += graph[i].size();
    }
    edge_num >>= 1;
    if (edge_num == 0) {
      trail = {s == -1 ? 0 : s};
      return true;
    }
    if (odd_deg == 0) {
      if (s == -1) {
        for (int i = 0; i < n; ++i) {
          if (!graph[i].empty()) {
            s = i;
            break;
          }
        }
      }
    } else if (odd_deg != 2) {
      return false;
    }
    for (int i = 0; i < n; ++i) {
      is_visited[i].assign(graph[i].size(), false);
    }
    dfs(s);
    if (static_cast<int>(trail.size()) == edge_num + 1) {
      std::reverse(trail.begin(), trail.end());
      return true;
    }
    trail.clear();
    return false;
  }

 private:
  struct Edge {
    int dst, rev;
    explicit Edge(const int dst, const int rev) : dst(dst), rev(rev) {}
  };

  const int n;
  std::vector<std::vector<bool>> is_visited;
  std::vector<std::vector<Edge>> graph;

  void dfs(const int ver) {
    const int deg = graph[ver].size();
    for (int i = 0; i < deg; ++i) {
      if (!is_visited[ver][i]) {
        const int dst = graph[ver][i].dst;
        is_visited[ver][i] = true;
        is_visited[dst][graph[ver][i].rev] = true;
        dfs(dst);
      }
    }
    trail.emplace_back(ver);
  }
};
