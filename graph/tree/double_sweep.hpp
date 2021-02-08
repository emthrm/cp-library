/**
 * @brief double sweep
 * @docs docs/graph/tree/diameter.md
 */

#pragma once
#include <cassert>
#include <tuple>
#include <utility>
#include <vector>
#include "../edge.hpp"

template <typename CostType>
struct DoubleSweep {
  int s = -1, t;
  CostType diameter;
  std::vector<int> path;

  DoubleSweep(const std::vector<std::vector<Edge<CostType>>> &graph) : graph(graph) {
    s = dfs1(-1, 0).second;
    std::tie(diameter, t) = dfs1(-1, s);
  }

  void build_path() {
    assert(s != -1);
    path.emplace_back(s);
    dfs2(-1, s);
  }

private:
  using Pci = std::pair<CostType, int>;

  const std::vector<std::vector<Edge<CostType>>> graph;

  Pci dfs1(int par, int ver) {
    Pci res = {0, ver};
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) {
        Pci pr = dfs1(ver, e.dst);
        pr.first += e.cost;
        if (pr.first > res.first) res = pr;
      }
    }
    return res;
  }

  bool dfs2(int par, int ver) {
    if (ver == t) return true;
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) {
        path.emplace_back(e.dst);
        if (dfs2(ver, e.dst)) return true;
        path.pop_back();
      }
    }
    return false;
  }
};
