#pragma once
#include <algorithm>
#include <utility>
#include <vector>

struct Lowlink {
  std::vector<int> order, lowlink, articulation_points;
  std::vector<std::pair<int, int>> bridges;
  const std::vector<std::vector<int>> graph;

  explicit Lowlink(const std::vector<std::vector<int>>& graph)
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
    for (const int e : graph[ver]) {
      if (order[e] == -1) {
        ++num;
        dfs(ver, e, t);
        lowlink[ver] = std::min(lowlink[ver], lowlink[e]);
        if (order[ver] <= lowlink[e]) {
          is_articulation_point = true;
          if (order[ver] < lowlink[e]) {
            bridges.emplace_back(std::minmax(ver, e));
          }
        }
      } else if (e != par) {
        lowlink[ver] = std::min(lowlink[ver], order[e]);
      }
    }
    if ((par == -1 && num >= 2) || (par != -1 && is_articulation_point)) {
      articulation_points.emplace_back(ver);
    }
  }
};
