#pragma once
#include <algorithm>
#include <vector>

#include "edge.hpp"

template <typename CostType>
struct Lowlink {
  std::vector<int> order, lowlink, articulation_points;
  std::vector<Edge<CostType>> bridges;
  const std::vector<std::vector<Edge<CostType>>> graph;

  explicit Lowlink(const std::vector<std::vector<Edge<CostType>>>& graph)
      : graph(graph) {
    const int n = graph.size();
    order.assign(n, -1);
    lowlink.resize(n);
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (order[i] == -1) dfs(-1, i, &t);
    }
  }

private:
  void dfs(const int par, const int ver, int* t) {
    order[ver] = lowlink[ver] = (*t)++;
    int num = 0;
    bool is_articulation_point = false;
    for (const Edge<CostType>& e : graph[ver]) {
      if (order[e.dst] == -1) {
        ++num;
        dfs(ver, e.dst, t);
        lowlink[ver] = std::min(lowlink[ver], lowlink[e.dst]);
        if (order[ver] <= lowlink[e.dst]) {
          is_articulation_point = true;
          if (order[ver] < lowlink[e.dst]) {
            bridges.emplace_back(std::min(ver, e.dst), std::max(ver, e.dst),
                                 e.cost);
          }
        }
      } else if (e.dst != par) {
        lowlink[ver] = std::min(lowlink[ver], order[e.dst]);
      }
    }
    if ((par == -1 && num >= 2) || (par != -1 && is_articulation_point)) {
      articulation_points.emplace_back(ver);
    }
  }
};
