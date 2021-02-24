#pragma once
#include <cassert>
#include <functional>
#include <tuple>
#include <utility>
#include <vector>

std::pair<int, std::vector<int>> double_sweep(const std::vector<std::vector<int>> &graph) {
  std::function<std::pair<int, int>(int, int)> dfs1 = [&graph, &dfs1](int par, int ver) -> std::pair<int, int> {
    std::pair<int, int> res = {0, ver};
    for (int e : graph[ver]) {
      if (e != par) {
        std::pair<int, int> pr = dfs1(ver, e);
        ++pr.first;
        if (pr.first > res.first) res = pr;
      }
    }
    return res;
  };
  int s = dfs1(-1, 0).second;
  int diameter, t;
  std::tie(diameter, t) = dfs1(-1, s);
  std::vector<int> path{s};
  std::function<bool(int, int)> dfs2 = [&graph, &t, &path, &dfs2](int par, int ver) -> bool {
    if (ver == t) return true;
    for (int e : graph[ver]) {
      if (e != par) {
        path.emplace_back(e);
        if (dfs2(ver, e)) return true;
        path.pop_back();
      }
    }
    return false;
  };
  assert(dfs2(-1, s));
  return {diameter, path};
}
