/**
 * @brief 最小共通祖先 ダブリング版
 * @docs docs/graph/tree/lowest_common_ancestor.md
 */

#pragma once
#include <cassert>
#include <utility>
#include <vector>
#include "../edge.hpp"

template <typename CostType>
struct LowestCommonAncestorByDoubling {
  std::vector<int> depth;
  std::vector<CostType> dist;

  LowestCommonAncestorByDoubling(const std::vector<std::vector<Edge<CostType>>> &graph) : graph(graph) {
    n = graph.size();
    depth.resize(n);
    dist.resize(n);
    while ((1 << table_h) <= n) ++table_h;
    parent.resize(table_h, std::vector<int>(n));
  }

  void build(int root = 0) {
    is_built = true;
    dfs(-1, root, 0, 0);
    for (int i = 0; i + 1 < table_h; ++i) for (int ver = 0; ver < n; ++ver) {
      parent[i + 1][ver] = parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]];
    }
  }

  int query(int u, int v) const {
    assert(is_built);
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int i = 0; i < table_h; ++i) {
      if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];
    }
    if (u == v) return u;
    for (int i = table_h - 1; i >= 0; --i) {
      if (parent[i][u] != parent[i][v]) {
        u = parent[i][u];
        v = parent[i][v];
      }
    }
    return parent[0][u];
  }

  CostType distance(int u, int v) const {
    assert(is_built);
    return dist[u] + dist[v] - dist[query(u, v)] * 2;
  }

private:
  bool is_built = false;
  int n, table_h = 1;
  std::vector<std::vector<Edge<CostType>>> graph;
  std::vector<std::vector<int>> parent;

  void dfs(int par, int ver, int now_depth, CostType now_dist) {
    depth[ver] = now_depth;
    dist[ver] = now_dist;
    parent[0][ver] = par;
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) dfs(ver, e.dst, now_depth + 1, now_dist + e.cost);
    }
  }
};
