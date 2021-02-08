#pragma once
#include <cassert>
#include <tuple>
#include <utility>
#include <vector>

struct DoubleSweep {
  int s = -1, t, diameter;
  std::vector<int> path;

  DoubleSweep(const std::vector<std::vector<int>> &graph) : graph(graph) {
    s = dfs1(-1, 0).second;
    std::tie(diameter, t) = dfs1(-1, s);
  }

  void build_path() {
    assert(s != -1);
    path.emplace_back(s);
    dfs2(-1, s);
  }

private:
  using P = std::pair<int, int>;

  const std::vector<std::vector<int>> graph;

  P dfs1(int par, int ver) {
    P res = {0, ver};
    for (int e : graph[ver]) {
      if (e != par) {
        P pr = dfs1(ver, e);
        ++pr.first;
        if (pr.first > res.first) res = pr;
      }
    }
    return res;
  }

  bool dfs2(int par, int ver) {
    if (ver == t) return true;
    for (int e : graph[ver]) {
      if (e != par) {
        path.emplace_back(e);
        if (dfs2(ver, e)) return true;
        path.pop_back();
      }
    }
    return false;
  }
};
