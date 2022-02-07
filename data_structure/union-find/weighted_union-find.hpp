/**
 * @brief 重みつき union-find
 * @docs docs/data_structure/union-find/union-find.md
 */

#pragma once
#include <utility>
#include <vector>

template <typename Abelian>
struct WeightedUnionFind {
  explicit WeightedUnionFind(const int n, const Abelian ID = 0)
      : ID(ID), parent(n, -1), data(n, ID) {}

  int root(const int ver) {
    if (parent[ver] < 0) return ver;
    const int r = root(parent[ver]);
    data[ver] += data[parent[ver]];
    return parent[ver] = r;
  }

  bool unite(int u, int v, Abelian wt) {
    wt += weight(u);
    wt -= weight(v);
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (parent[u] > parent[v]) {
      std::swap(u, v);
      wt = -wt;
    }
    parent[u] += parent[v];
    parent[v] = u;
    data[v] = wt;
    return true;
  }

  bool is_same(const int u, const int v) { return root(u) == root(v); }

  int size(const int ver) { return -parent[root(ver)]; }

  Abelian diff(const int u, const int v) { return weight(v) - weight(u); }

private:
  const Abelian ID;
  std::vector<int> parent;
  std::vector<Abelian> data;

  Abelian weight(const int ver) {
    root(ver);
    return data[ver];
  }
};
