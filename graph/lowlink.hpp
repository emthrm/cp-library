#pragma once
#include <algorithm>
#include <vector>
#include "edge.hpp"

template <typename CostType>
struct Lowlink {
  std::vector<std::vector<Edge<CostType>>> graph;
  std::vector<int> ap;
  std::vector<Edge<CostType>> bridge;

  Lowlink(const std::vector<std::vector<Edge<CostType>>> &graph) : graph(graph) {
    int n = graph.size();
    order.assign(n, -1);
    lowlink.resize(n);
    int tm = 0;
    for (int i = 0; i < n; ++i) {
      if (order[i] == -1) dfs(-1, i, tm);
    }
    // std::sort(ap.begin(), ap.end());
    // std::sort(bridge.begin(), bridge.end(), [](const Edge<CostType> &a, const Edge<CostType> &b) -> bool {
    //   return a.src != b.src ? a.src < b.src : a.dst != b.dst ? a.dst < b.dst : a.cost < b.cost;
    // });
  }

  std::vector<int> order, lowlink;
private:
  void dfs(int par, int ver, int &tm) {
    order[ver] = lowlink[ver] = tm++;
    int cnt = 0;
    bool is_ap = false;
    for (const Edge<CostType> &e : graph[ver]) {
      if (order[e.dst] == -1) {
        ++cnt;
        dfs(ver, e.dst, tm);
        if (lowlink[e.dst] < lowlink[ver]) lowlink[ver] = lowlink[e.dst];
        if (order[ver] <= lowlink[e.dst]) {
          is_ap = true;
          if (order[ver] < lowlink[e.dst]) bridge.emplace_back(std::min(ver, e.dst), std::max(ver, e.dst), e.cost);
        }
      } else if (e.dst != par) {
        if (order[e.dst] < lowlink[ver]) lowlink[ver] = order[e.dst];
      }
    }
    if (par == -1) {
      if (cnt >= 2) ap.emplace_back(ver);
    } else {
      if (is_ap) ap.emplace_back(ver);
    }
  }
};
