/**
 * @brief undo 可能 union-find
 * @docs docs/data_structure/union-find/union-find.md
 */

#ifndef EMTHRM_DATA_STRUCTURE_UNION_FIND_UNDOABLE_UNION_FIND_HPP_
#define EMTHRM_DATA_STRUCTURE_UNION_FIND_UNDOABLE_UNION_FIND_HPP_

#include <utility>
#include <vector>

namespace emthrm {

struct UndoableUnionFind {
  explicit UndoableUnionFind(const int n) : data(n, -1) {}

  int root(const int ver) const {
    return data[ver] < 0 ? ver : root(data[ver]);
  }

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

  bool is_same(const int u, const int v) const { return root(u) == root(v); }

  int size(const int ver) const { return -data[root(ver)]; }

  void undo() {
    for (int i = 0; i < 2; ++i) {
      data[history.back().first] = history.back().second;
      history.pop_back();
    }
  }

  void snapshot() { history.clear(); }

  void rollback() {
    while (!history.empty()) undo();
  }

 private:
  std::vector<int> data;
  std::vector<std::pair<int, int>> history;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_UNION_FIND_UNDOABLE_UNION_FIND_HPP_
