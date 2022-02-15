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

  explicit LowestCommonAncestorByDoubling(
      const std::vector<std::vector<Edge<CostType>>>& graph)
      : is_built(false), n(graph.size()), table_h(1), graph(graph) {
    depth.resize(n);
    dist.resize(n);
    while ((1 << table_h) <= n) ++table_h;
    parent.resize(table_h, std::vector<int>(n));
  }

  void build(const int root = 0) {
    is_built = true;
    dfs(-1, root, 0, 0);
    for (int i = 0; i + 1 < table_h; ++i) {
      for (int ver = 0; ver < n; ++ver) {
        parent[i + 1][ver] =
            (parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]]);
      }
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
    return parent.front()[u];
  }

  CostType distance(const int u, const int v) const {
    assert(is_built);
    return dist[u] + dist[v] - dist[query(u, v)] * 2;
  }

private:
  bool is_built;
  const int n;
  int table_h;
  std::vector<std::vector<int>> parent;
  const std::vector<std::vector<Edge<CostType>>> graph;

  void dfs(const int par, const int ver, const int cur_depth,
           const CostType cur_dist) {
    depth[ver] = cur_depth;
    dist[ver] = cur_dist;
    parent.front()[ver] = par;
    for (const Edge<CostType>& e : graph[ver]) {
      if (e.dst != par) dfs(ver, e.dst, cur_depth + 1, cur_dist + e.cost);
    }
  }
};
