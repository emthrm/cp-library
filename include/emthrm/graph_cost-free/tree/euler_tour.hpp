#ifndef EMTHRM_GRAPH_COST_FREE_TREE_EULER_TOUR_HPP_
#define EMTHRM_GRAPH_COST_FREE_TREE_EULER_TOUR_HPP_

#include <vector>

namespace emthrm {

struct EulerTour {
  std::vector<int> tour, depth, left, right, down, up;

  explicit EulerTour(const std::vector<std::vector<int>>& graph,
                     const int root = 0)
      : graph(graph) {
    const int n = graph.size();
    left.resize(n);
    right.resize(n);
    down.assign(n, -1);
    up.assign(n, (n - 1) << 1);
    int idx = 0;
    dfs(-1, root, 0, &idx);
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
  const std::vector<std::vector<int>> graph;

  void dfs(const int par, const int ver, int cur_depth, int* idx) {
    left[ver] = tour.size();
    tour.emplace_back(ver);
    depth.emplace_back(cur_depth);
    for (const int e : graph[ver]) {
      if (e != par) [[likely]] {
        down[e] = (*idx)++;
        dfs(ver, e, cur_depth + 1, idx);
        tour.emplace_back(ver);
        depth.emplace_back(cur_depth);
        up[e] = (*idx)++;
      }
    }
    right[ver] = tour.size() - 1;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_TREE_EULER_TOUR_HPP_
