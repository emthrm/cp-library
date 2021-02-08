/**
 * @brief undo 可能 union-find 木
 * @docs docs/data_structure/union-find/union-find.md
 */

#pragma once
#include <utility>
#include <vector>

struct UndoableUnionFind {
  UndoableUnionFind(int n) : data(n, -1) {}

  int root(int ver) const { return data[ver] < 0 ? ver : root(data[ver]); }

  bool unite(int u, int v) {
    u = root(u);
    history.emplace_back(u, data[u]);
    v = root(v);
    history.emplace_back(v, data[v]);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool same(int u, int v) const { return root(u) == root(v); }

  int size(int ver) const { return -data[root(ver)]; }

  void undo() {
    for (int i = 0; i < 2; ++i) {
      data[history.back().first] = history.back().second;
      history.pop_back();
    }
  }

  void snap() { history.clear(); }

  void rollback() { while (!history.empty()) undo(); }

private:
  std::vector<int> data;
  std::vector<std::pair<int, int>> history;
};
