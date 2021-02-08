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

  EulerianTrailInUndirectedGraph(int n) : n(n), graph(n), visited(n) {}

  void add_edge(int u, int v) {
    graph[u].emplace_back(v, graph[v].size());
    graph[v].emplace_back(u, graph[u].size() - 1);
  }

  bool build(int s = -1) {
    trail.clear();
    int odd = 0, edges = 0;
    for (int i = 0; i < n; ++i) {
      if (graph[i].size() & 1) {
        ++odd;
        if (s == -1) s = i;
      }
      edges += graph[i].size();
    }
    if (s == -1) {
      for (int i = 0; i < n; ++i) {
        if (!graph[i].empty()) {
          s = i;
          break;
        }
      }
      if (s == -1) {
        assert(edges == 0);
        trail.emplace_back(0);
        return true;
      }
    }
    for (int i = 0; i < n; ++i) visited[i].assign(graph[i].size(), false);
    if (odd == 0 || (odd == 2 && (graph[s].size() & 1))) {
      dfs(s);
      if (trail.size() == (edges >> 1) + 1) {
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
    Edge(int dst, int rev) : dst(dst), rev(rev) {}
  };

  int n;
  std::vector<std::vector<Edge>> graph;
  std::vector<std::vector<bool>> visited;

  void dfs(int ver) {
    int sz = graph[ver].size();
    for (int i = 0; i < sz; ++i) {
      if (!visited[ver][i]) {
        int nx = graph[ver][i].dst;
        visited[ver][i] = visited[nx][graph[ver][i].rev] = true;
        dfs(nx);
      }
    }
    trail.emplace_back(ver);
  }
};
