#pragma once
#include <vector>
#include "../edge.hpp"

template <typename CostType>
struct CentroidDecomposition {
  int root;
  std::vector<std::vector<int>> comp;
  std::vector<int> par;

  CentroidDecomposition(const std::vector<std::vector<Edge<CostType>>> &graph) : graph(graph) {
    int n = graph.size();
    alive.assign(n, true);
    subtree.resize(n);
    comp.resize(n);
    par.assign(n, -1);
    root = build(0);
  }

private:
  const std::vector<std::vector<Edge<CostType>>> graph;
  std::vector<bool> alive;
  std::vector<int> subtree;

  int build(int s) {
    int centroid = search_centroid(-1, s, calc_subtree(-1, s) / 2);
    alive[centroid] = false;
    for (const Edge<CostType> &e : graph[centroid]) {
      if (alive[e.dst]) {
        comp[centroid].emplace_back(build(e.dst));
        par[e.dst] = centroid;
      }
    }
    alive[centroid] = true;
    return centroid;
  }

  int calc_subtree(int par, int ver) {
    subtree[ver] = 1;
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par && alive[e.dst]) subtree[ver] += calc_subtree(ver, e.dst);
    }
    return subtree[ver];
  }

  int search_centroid(int par, int ver, int half) const {
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par && alive[e.dst] && subtree[e.dst] > half) return search_centroid(ver, e.dst, half);
    }
    return ver;
  }
};
