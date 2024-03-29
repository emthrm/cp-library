#ifndef EMTHRM_DATA_STRUCTURE_UNION_FIND_UNION_FIND_HPP_
#define EMTHRM_DATA_STRUCTURE_UNION_FIND_UNION_FIND_HPP_

#include <utility>
#include <vector>

namespace emthrm {

struct UnionFind {
  explicit UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) { return root(u) == root(v); }

  int size(const int ver) { return -data[root(ver)]; }

 private:
  std::vector<int> data;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_UNION_FIND_UNION_FIND_HPP_
