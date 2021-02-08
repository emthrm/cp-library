#pragma once
#include <vector>

struct EulerTour {
  std::vector<int> tour, left, right, down, up, depth;

  EulerTour(const std::vector<std::vector<int>> &graph, int root = 0) : graph(graph) {
    int n = graph.size();
    left.resize(n);
    right.resize(n);
    down.assign(n, -1);
    up.assign(n, (n - 1) << 1);
    int idx = 0;
    dfs(-1, root, 0, idx);
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
  const std::vector<std::vector<int>> graph;

  void dfs(int par, int ver, int now_depth, int &idx) {
    left[ver] = tour.size();
    tour.emplace_back(ver);
    depth.emplace_back(now_depth);
    for (int e : graph[ver]) {
      if (e != par) {
        down[e] = idx++;
        dfs(ver, e, now_depth + 1, idx);
        tour.emplace_back(ver);
        depth.emplace_back(now_depth);
        up[e] = idx++;
      }
    }
    right[ver] = tour.size() - 1;
  }
};
