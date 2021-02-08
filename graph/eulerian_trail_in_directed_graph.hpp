/**
 * @brief オイラー路 有向グラフ版
 * @docs docs/graph/eulerian_trail.md
 */

#pragma once
#include <algorithm>
#include <functional>
#include <vector>
#include "edge.hpp"

template <typename CostType>
std::vector<int> eulerian_trail_in_directed_graph(const std::vector<std::vector<Edge<CostType>>> &graph, int s = -1) {
  int n = graph.size(), edges = 0;
  std::vector<std::vector<Edge<CostType>>> tmp(graph);
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    deg[i] += tmp[i].size();
    for (const Edge<CostType> &e : tmp[i]) --deg[e.dst];
    edges += tmp[i].size();
  }
  int not0 = n - std::count(deg.begin(), deg.end(), 0);
  if (s == -1) {
    for (int i = 0; i < n; ++i) {
      if (not0 == 0) {
        if (!tmp[i].empty()) {
          s = i;
          break;
        }
      } else if (not0 == 2) {
        if (deg[i] == 1) {
          s = i;
          break;
        }
      }
    }
    if (s == -1) return {};
  }
  if (not0 == 0 || (not0 == 2 && deg[s] == 1)) {
    std::vector<int> res;
    std::function<void(int)> dfs = [&tmp, &res, &dfs](int ver) {
      while (!tmp[ver].empty()) {
        int nx = tmp[ver].back().dst;
        tmp[ver].pop_back();
        dfs(nx);
      }
      res.emplace_back(ver);
    };
    dfs(s);
    if (res.size() == edges + 1) {
      std::reverse(res.begin(), res.end());
      return res;
    }
  }
  return {};
}
