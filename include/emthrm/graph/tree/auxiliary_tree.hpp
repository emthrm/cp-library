#ifndef EMTHRM_GRAPH_TREE_AUXILIARY_TREE_HPP_
#define EMTHRM_GRAPH_TREE_AUXILIARY_TREE_HPP_

#include <algorithm>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp"

namespace emthrm {

template <typename CostType>
struct AuxiliaryTree {
  LowestCommonAncestor<CostType> euler_tour;

  explicit AuxiliaryTree(
      const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0)
      : euler_tour(graph, root), depth(graph.size(), 0) {
    const auto dfs = [this, &graph](
        auto dfs, const int par, const int ver) -> void {
      for (const Edge<CostType>& e : graph[ver]) {
        if (e.dst == par) continue;
        depth[e.dst] = depth[ver] + e.cost;
        dfs(dfs, ver, e.dst);
      }
    };
    dfs(dfs, -1, root);
  }

  std::pair<std::vector<std::vector<Edge<CostType>>>,
            std::vector<int>> query(std::vector<int> vertices) const {
    if (vertices.empty()) [[unlikely]] return {};
    static std::vector<int> mp(depth.size(), -1);
    std::ranges::sort(vertices, {},
                      [&](const int v) -> int { return euler_tour.left[v]; });
    std::vector<std::vector<Edge<CostType>>> graph;
    std::vector<int> inv;
    const auto add_vertex = [this, &graph, &inv](const int v) -> void {
      mp[v] = graph.size();
      graph.emplace_back();
      inv.emplace_back(v);
    };
    const auto add_edge = [this, &graph](int u, int v) -> void {
      const CostType cost = depth[v] - depth[u];
      u = mp[u];
      v = mp[v];
      graph[u].emplace_back(u, v, cost);
      graph[v].emplace_back(v, u, cost);
    };
    add_vertex(vertices.front());
    std::vector<int> stck{vertices.front()};
    for (const int i : std::views::iota(1, std::ssize(vertices))) {
      const int l = euler_tour.query(vertices[i - 1], vertices[i]);
      if (mp[l] == -1) add_vertex(l);
      if (l != vertices[i - 1]) {
        const int depth_l = euler_tour.depth[euler_tour.left[l]];
        int cur = stck.back();
        stck.pop_back();
        while (!stck.empty() &&
               euler_tour.depth[euler_tour.left[stck.back()]] > depth_l) {
          add_edge(stck.back(), cur);
          cur = stck.back();
          stck.pop_back();
        }
        add_edge(l, cur);
        if (stck.empty() || stck.back() != l) stck.emplace_back(l);
      }
      add_vertex(vertices[i]);
      stck.emplace_back(vertices[i]);
    }
    for (; stck.size() >= 2; stck.pop_back()) {
      add_edge(stck.end()[-2], stck.back());
    }
    for (const int v : inv) mp[v] = -1;
    return {graph, inv};
  }

 private:
  std::vector<CostType> depth;
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_TREE_AUXILIARY_TREE_HPP_
