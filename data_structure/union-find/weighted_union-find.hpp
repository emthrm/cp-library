/**
 * @brief 重みつき union-find
 * @docs docs/data_structure/union-find/union-find.md
 */

#pragma once
#include <utility>
#include <vector>

template <typename Abelian>
struct WeightedUnionFind {
  WeightedUnionFind(const int n, const Abelian ID = 0) : ID(ID), par(n, -1), data(n, ID) {}

  int root(const int ver) {
    if (par[ver] < 0) return ver;
    const int r = root(par[ver]);
    data[ver] += data[par[ver]];
    return par[ver] = r;
  }

  bool unite(int u, int v, Abelian wt) {
    wt += weight(u);
    wt -= weight(v);
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (par[u] > par[v]) {
      std::swap(u, v);
      wt = -wt;
    }
    par[u] += par[v];
    par[v] = u;
    data[v] = wt;
    return true;
  }

  bool is_same(const int u, const int v) {
    return root(u) == root(v);
  }

  int size(const int ver) {
    return -par[root(ver)];
  }

  Abelian diff(const int u, const int v) {
    return weight(v) - weight(u);
  }

private:
  const Abelian ID;
  std::vector<int> par;
  std::vector<Abelian> data;

  Abelian weight(const int ver) {
    root(ver);
    return data[ver];
  }
};
