#pragma once
#include <cassert>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>
#include "../edge.hpp"

template <typename CostType>
std::pair<CostType, std::vector<int>> double_sweep(const std::vector<std::vector<Edge<CostType>>> &graph) {
  std::function<std::pair<CostType, int>(int, int)> dfs1 = [&graph, &dfs1](int par, int ver) -> std::pair<CostType, int> {
    std::pair<CostType, int> res = {0, ver};
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) {
        std::pair<CostType, int> pr = dfs1(ver, e.dst);
        pr.first += e.cost;
        if (pr.first > res.first) res = pr;
      }
    }
    return res;
  };
  int s = dfs1(-1, 0).second;
  CostType diameter;
  int t;
  std::tie(diameter, t) = dfs1(-1, s);
  std::vector<int> path{s};
  std::function<bool(int, int)> dfs2 = [&graph, &t, &path, &dfs2](int par, int ver) -> bool {
    if (ver == t) return true;
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) {
        path.emplace_back(e.dst);
        if (dfs2(ver, e.dst)) return true;
        path.pop_back();
      }
    }
    return false;
  };
  assert(dfs2(-1, s));
  return {diameter, path};
}
