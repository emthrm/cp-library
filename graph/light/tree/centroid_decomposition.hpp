#pragma once
#include <vector>

struct CentroidDecomposition {
  int root;
  std::vector<std::vector<int>> comp;
  std::vector<int> par;

  CentroidDecomposition(const std::vector<std::vector<int>> &graph) : graph(graph) {
    int n = graph.size();
    alive.assign(n, true);
    subtree.resize(n);
    comp.resize(n);
    par.assign(n, -1);
    root = build(0);
  }

private:
  const std::vector<std::vector<int>> graph;
  std::vector<bool> alive;
  std::vector<int> subtree;

  int build(int s) {
    int centroid = search_centroid(-1, s, calc_subtree(-1, s) / 2);
    alive[centroid] = false;
    for (int e : graph[centroid]) {
      if (alive[e]) {
        comp[centroid].emplace_back(build(e));
        par[e] = centroid;
      }
    }
    alive[centroid] = true;
    return centroid;
  }

  int calc_subtree(int par, int ver) {
    subtree[ver] = 1;
    for (int e : graph[ver]) {
      if (e != par && alive[e]) subtree[ver] += calc_subtree(ver, e);
    }
    return subtree[ver];
  }

  int search_centroid(int par, int ver, int half) const {
    for (int e : graph[ver]) {
      if (e != par && alive[e] && subtree[e] > half) return search_centroid(ver, e, half);
    }
    return ver;
  }
};
