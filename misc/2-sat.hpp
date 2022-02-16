#pragma once
#include <algorithm>
#include <vector>

struct TwoSat {
  explicit TwoSat(const int n)
      : n(n), graph(n << 1), rgraph(n << 1), is_visited(n << 1), ids(n << 1) {
    order.reserve(n << 1);
  }

  int negate(const int x) const { return (n + x) % (n << 1); }

  void add_or(const int x, const int y) {
    graph[negate(x)].emplace_back(y);
    graph[negate(y)].emplace_back(x);
    rgraph[y].emplace_back(negate(x));
    rgraph[x].emplace_back(negate(y));
  }

  void add_if(const int x, const int y) { add_or(negate(x), y); }

  void add_nand(const int x, const int y) { add_or(negate(x), negate(y)); }

  void set_true(const int x) { add_or(x, x); }

  void set_false(const int x) { set_true(negate(x)); }

  std::vector<bool> build() {
    std::fill(is_visited.begin(), is_visited.end(), false);
    std::fill(ids.begin(), ids.end(), -1);
    order.clear();
    for (int i = 0; i < (n << 1); ++i) {
      if (!is_visited[i]) dfs(i);
    }
    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {
      if (ids[order[i]] == -1) rdfs(order[i], id++);
    }
    std::vector<bool> res(n);
    for (int i = 0; i < n; ++i) {
      if (ids[i] == ids[negate(i)]) return {};
      res[i] = ids[negate(i)] < ids[i];
    }
    return res;
  }

 private:
  const int n;
  std::vector<std::vector<int>> graph, rgraph;
  std::vector<bool> is_visited;
  std::vector<int> ids, order;

  void dfs(const int ver) {
    is_visited[ver] = true;
    for (const int dst : graph[ver]) {
      if (!is_visited[dst]) dfs(dst);
    }
    order.emplace_back(ver);
  }

  void rdfs(const int ver, const int cur_id) {
    ids[ver] = cur_id;
    for (const int dst : rgraph[ver]) {
      if (ids[dst] == -1) rdfs(dst, cur_id);
    }
  }
};
