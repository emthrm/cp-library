/**
 * @brief 部分永続 union-find
 * @docs docs/data_structure/union-find/union-find.md
 */

#pragma once
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

struct PartiallyPersistentUnionFind {
  PartiallyPersistentUnionFind(int n) : data(n, -1), last(n, -1), history(n, {{-1, -1}}) {}

  int root(int t, int ver) const {
    return last[ver] == -1 || t < last[ver] ? ver : root(t, data[ver]);
  }

  bool unite(int t, int u, int v) {
    u = root(t, u);
    v = root(t, v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    last[v] = t;
    history[u].emplace_back(t, data[u]);
    return true;
  }

  bool same(int t, int u, int v) const { return root(t, u) == root(t, v); }

  int size(int t, int ver) const {
    ver = root(t, ver);
    return -std::prev(std::lower_bound(history[ver].begin(), history[ver].end(), std::make_pair(t, 0)))->second;
  }

private:
  std::vector<int> data, last;
  std::vector<std::vector<std::pair<int, int>>> history;
};
