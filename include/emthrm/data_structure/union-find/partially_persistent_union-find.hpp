/**
 * @title 部分永続 union-find
 * @docs docs/data_structure/union-find/union-find.md
 */

#ifndef EMTHRM_DATA_STRUCTURE_UNION_FIND_PARTIALLY_PERSISTENT_UNION_FIND_HPP_
#define EMTHRM_DATA_STRUCTURE_UNION_FIND_PARTIALLY_PERSISTENT_UNION_FIND_HPP_

#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>

namespace emthrm {

struct PartiallyPersistentUnionFind {
  explicit PartiallyPersistentUnionFind(const int n)
      : data(n, -1), last(n, -1), history(n, {{-1, -1}}) {}

  int root(const int t, const int ver) const {
    return last[ver] == -1 || t < last[ver] ? ver : root(t, data[ver]);
  }

  bool unite(const int t, int u, int v) {
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

  bool is_same(const int t, const int u, const int v) const {
    return root(t, u) == root(t, v);
  }

  int size(const int t, int ver) const {
    ver = root(t, ver);
    return -std::prev(std::lower_bound(history[ver].begin(),
                                       history[ver].end(),
                                       std::make_pair(t, 0)))->second;
  }

 private:
  std::vector<int> data, last;
  std::vector<std::vector<std::pair<int, int>>> history;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_UNION_FIND_PARTIALLY_PERSISTENT_UNION_FIND_HPP_
