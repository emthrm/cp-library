#pragma once
#include <vector>
#include "../graph/edge.hpp"
#include "../graph/scc.hpp"

struct TwoSat {
  TwoSat(int n) : n(n), graph(n << 1) {}

  int negate(int x) const { return (n + x) % (n << 1); }

  void add_or(int x, int y) {
    graph[negate(x)].emplace_back(negate(x), y);
    graph[negate(y)].emplace_back(negate(y), x);
  }

  void add_if(int x, int y) { add_or(negate(x), y); }

  void add_nand(int x, int y) { add_or(negate(x), negate(y)); }

  void set_true(int x) { add_or(x, x); }

  void set_false(int x) { set_true(negate(x)); }

  std::vector<bool> build() const {
    SCC<bool> scc(graph);
    std::vector<bool> res(n);
    for (int i = 0; i < n; ++i) {
      if (scc.id[i] == scc.id[negate(i)]) return {};
      res[i] = scc.id[negate(i)] < scc.id[i];
    }
    return res;
  }

private:
  int n;
  std::vector<std::vector<Edge<bool>>> graph;
};
