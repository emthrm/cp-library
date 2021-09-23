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

  EulerianTrailInUndirectedGraph(const int n) : n(n), graph(n), is_visited(n) {}

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
        if (s == -1) {
          s = i;
        }
      }
      edge_num += graph[i].size();
    }
    if (s == -1) {
      for (int i = 0; i < n; ++i) {
        if (!graph[i].empty()) {
          s = i;
          break;
        }
      }
      if (s == -1) {
        assert(edge_num == 0);
        trail.emplace_back(0);
        return true;
      }
    }
    for (int i = 0; i < n; ++i) {
      is_visited[i].assign(graph[i].size(), false);
    }
    if (odd_deg == 0 || (odd_deg == 2 && (graph[s].size() & 1))) {
      dfs(s);
      if (trail.size() == (edge_num >> 1) + 1) {
        std::reverse(trail.begin(), trail.end());
        return true;
      }
      trail.clear();
    }
    return false;
  }

private:
  struct Edge {
    int dst, rev;
    Edge(const int dst, const int rev) : dst(dst), rev(rev) {}
  };

  const int n;
  std::vector<std::vector<Edge>> graph;
  std::vector<std::vector<int>> is_visited;

  void dfs(const int ver) {
    const int deg = graph[ver].size();
    for (int i = 0; i < deg; ++i) {
      if (!is_visited[ver][i]) {
        const int dst = graph[ver][i].dst;
        is_visited[ver][i] = is_visited[dst][graph[ver][i].rev] = true;
        dfs(dst);
      }
    }
    trail.emplace_back(ver);
  }
};
