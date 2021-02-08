#pragma once
#include <vector>
#include "../edge.hpp"

template <typename CostType>
struct EulerTour {
  std::vector<int> tour, left, right, down, up, depth;
  std::vector<CostType> cost;

  EulerTour(const std::vector<std::vector<Edge<CostType>>> &graph, int root = 0) : graph(graph) {
    int n = graph.size();
    left.resize(n);
    right.resize(n);
    down.assign(n, -1);
    up.assign(n, (n - 1) << 1);
    dfs(-1, root, 0);
  }

  template <typename Fn>
  void v_update(int ver, Fn f) const { f(left[ver], right[ver] + 1); }

  template <typename T, typename Fn>
  T v_query(int ver, Fn f) const { return f(left[ver], right[ver] + 1); }

  template <typename T, typename Fn>
  T e_query(int u, int v, Fn f) const { return f(down[u] + 1, down[v] + 1); }

  template <typename Fn>
  void subtree_e_update(int ver, Fn f) const { f(down[ver] + 1, up[ver]); }

  template <typename T, typename Fn>
  T subtree_e_query(int ver, Fn f) const { return f(down[ver] + 1, up[ver]); }

private:
  const std::vector<std::vector<Edge<CostType>>> graph;

  void dfs(int par, int ver, int now_depth) {
    left[ver] = tour.size();
    tour.emplace_back(ver);
    depth.emplace_back(now_depth);
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) {
        down[e.dst] = cost.size();
        cost.emplace_back(e.cost);
        dfs(ver, e.dst, now_depth + 1);
        tour.emplace_back(ver);
        depth.emplace_back(now_depth);
        up[e.dst] = cost.size();
        cost.emplace_back(-e.cost);
      }
    }
    right[ver] = tour.size() - 1;
  }
};
