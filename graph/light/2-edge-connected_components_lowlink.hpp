#pragma once
// #include <algorithm>
#include <utility>
#include <vector>
#include "lowlink.hpp"

struct TwoEdgeConnectedComponents : Lowlink {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, comp;

  TwoEdgeConnectedComponents(const std::vector<std::vector<int>> &graph, bool heavy = false) : Lowlink(graph), heavy(heavy) {
    int n = graph.size();
    id.assign(n, -1);
    int now = 0;
    for (int i = 0; i < n; ++i) {
      if (id[i] == -1) dfs(-1, i, now);
    }
    comp.resize(now);
    for (const std::pair<int, int> &e : this->bridge) {
      int u = id[e.first], v = id[e.second];
      comp[u].emplace_back(v);
      comp[v].emplace_back(u);
    }
    // if (heavy) {
    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());
    // }
  }

private:
  bool heavy;

  void dfs(int par, int ver, int &now) {
    if (par != -1 && this->order[par] >= this->lowlink[ver]) {
      id[ver] = id[par];
    } else {
      id[ver] = now++;
      if (heavy) vertices.emplace_back();
    }
    if (heavy) vertices[id[ver]].emplace_back(ver);
    for (int e : this->graph[ver]) {
      if (id[e] == -1) dfs(ver, e, now);
    }
  }
};
