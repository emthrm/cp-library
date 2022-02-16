#pragma once
#include <vector>

struct CentroidDecomposition {
  int root;
  std::vector<int> parent;
  std::vector<std::vector<int>> g;

  explicit CentroidDecomposition(const std::vector<std::vector<int>>& graph)
      : graph(graph) {
    const int n = graph.size();
    parent.assign(n, -1);
    g.resize(n);
    is_alive.assign(n, true);
    subtree.assign(n, 1);
    root = build(0);
  }

 private:
  std::vector<bool> is_alive;
  std::vector<int> subtree;
  const std::vector<std::vector<int>> graph;

  int build(const int s) {
    const int centroid = search_centroid(-1, s, calc_subtree(-1, s) / 2);
    is_alive[centroid] = false;
    for (const int e : graph[centroid]) {
      if (is_alive[e]) {
        g[centroid].emplace_back(build(e));
        parent[e] = centroid;
      }
    }
    is_alive[centroid] = true;
    return centroid;
  }

  int calc_subtree(const int par, const int ver) {
    for (const int e : graph[ver]) {
      if (e != par && is_alive[e]) subtree[ver] += calc_subtree(ver, e);
    }
    return subtree[ver];
  }

  int search_centroid(const int par, const int ver, const int half) const {
    for (const int e : graph[ver]) {
      if (e != par && is_alive[e] && subtree[e] > half) {
        return search_centroid(ver, e, half);
      }
    }
    return ver;
  }
};
