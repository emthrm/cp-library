#pragma once
#include <vector>

struct TwoSat {
  TwoSat(int n) : n(n), graph(n << 1), rev_graph(n << 1) {}

  int negate(int x) const { return (n + x) % (n << 1); }

  void add_or(int x, int y) {
    graph[negate(x)].emplace_back(y);
    graph[negate(y)].emplace_back(x);
    rev_graph[y].emplace_back(negate(x));
    rev_graph[x].emplace_back(negate(y));
  }

  void add_if(int x, int y) { add_or(negate(x), y); }

  void add_nand(int x, int y) { add_or(negate(x), negate(y)); }

  void set_true(int x) { add_or(x, x); }

  void set_false(int x) { set_true(negate(x)); }

  std::vector<bool> build() {
    used.assign(n << 1, false);
    id.assign(n << 1, -1);
    order.clear();
    for (int i = 0; i < (n << 1); ++i) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = (n << 1) - 1; i >= 0; --i) {
      if (id[order[i]] == -1) rev_dfs(order[i], now++);
    }
    std::vector<bool> res(n);
    for (int i = 0; i < n; ++i) {
      if (id[i] == id[negate(i)]) return {};
      res[i] = id[negate(i)] < id[i];
    }
    return res;
  }

private:
  int n;
  std::vector<std::vector<int>> graph, rev_graph;
  std::vector<bool> used;
  std::vector<int> id, order;

  void dfs(int ver) {
    used[ver] = true;
    for (int e : graph[ver]) {
      if (!used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    for (int e : rev_graph[ver]) {
      if (id[e] == -1) rev_dfs(e, now);
    }
  }
};
