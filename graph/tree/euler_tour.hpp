#pragma once
#include <vector>
#include "../edge.hpp"

template <typename CostType>
struct EulerTour {
  std::vector<int> tour, depth, left, right, down, up;
  std::vector<CostType> cost;

  explicit EulerTour(const std::vector<std::vector<Edge<CostType>>> &graph,
                     const int root = 0)
      : graph(graph) {
    const int n = graph.size();
    left.resize(n);
    right.resize(n);
    down.assign(n, -1);
    up.assign(n, (n - 1) << 1);
    dfs(-1, root, 0);
  }

  template <typename Fn>
  void update_v(const int ver, const Fn f) const {
    f(left[ver], right[ver] + 1);
  }

  template <typename T, typename Fn>
  T query_v(const int ver, const Fn f) const {
    return f(left[ver], right[ver] + 1);
  }

  template <typename T, typename Fn>
  T query_e(const int u, const int v, const Fn f) const {
    return f(down[u] + 1, down[v] + 1);
  }

  template <typename Fn>
  void update_subtree_e(const int ver, const Fn f) const {
    f(down[ver] + 1, up[ver]);
  }

  template <typename T, typename Fn>
  T query_subtree_e(const int ver, const Fn f) const {
    return f(down[ver] + 1, up[ver]);
  }

private:
  const std::vector<std::vector<Edge<CostType>>> graph;

  void dfs(const int par, const int ver, const int cur_depth) {
    left[ver] = tour.size();
    tour.emplace_back(ver);
    depth.emplace_back(cur_depth);
    for (const Edge<CostType>& e : graph[ver]) {
      if (e.dst != par) {
        down[e.dst] = cost.size();
        cost.emplace_back(e.cost);
        dfs(ver, e.dst, cur_depth + 1);
        tour.emplace_back(ver);
        depth.emplace_back(cur_depth);
        up[e.dst] = cost.size();
        cost.emplace_back(-e.cost);
      }
    }
    right[ver] = tour.size() - 1;
  }
};
