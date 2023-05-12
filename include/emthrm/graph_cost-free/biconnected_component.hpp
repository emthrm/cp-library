#ifndef EMTHRM_GRAPH_COST_FREE_BICONNECTED_COMPONENT_HPP_
#define EMTHRM_GRAPH_COST_FREE_BICONNECTED_COMPONENT_HPP_

// #include <algorithm>
#include <set>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/lowlink.hpp"

namespace emthrm {

template <bool IS_FULL_VER = false>
struct BiconnectedComponent : Lowlink {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, cutpoint;
  std::vector<std::vector<std::pair<int, int>>> block;

  explicit BiconnectedComponent(const std::vector<std::vector<int>>& graph)
      : Lowlink(graph) {
    const int n = graph.size();
    id.assign(n, -2);
    if constexpr (IS_FULL_VER) {
      cutpoint.resize(n);
      is_articulation_point.assign(n, false);
      for (const int articulation_point : this->articulation_points) {
        is_articulation_point[articulation_point] = true;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (id[i] == -2) dfs(-1, i);
    }
    // const int m = vertices.size();
    // for (int i = 0; i < m; ++i) {
    //   std::sort(block[i].begin(), block[i].end());
    // }
    // if constexpr (IS_FULL_VER) {
    //   for (int i = 0; i < m; ++i) {
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    //   for (int i = 0; i < n; ++i) {
    //     std::sort(cutpoint[i].begin(), cutpoint[i].end());
    //   }
    // }
  }

 private:
  std::vector<bool> is_articulation_point;
  std::vector<std::pair<int, int>> tmp;

  void dfs(const int par, const int ver) {
    id[ver] = -1;
    for (const int e : this->graph[ver]) {
      if (e == par) continue;
      int src = ver, dst = e;
      if (src > dst) std::swap(src, dst);
      if (id[e] == -2 || this->order[e] < this->order[ver]) {
        tmp.emplace_back(src, dst);
      }
      if (id[e] == -2) {
        dfs(ver, e);
        if (this->lowlink[e] >= this->order[ver]) {
          const int idx = block.size();
          block.emplace_back();
          std::set<int> st;
          while (true) {
            const std::pair<int, int> edge = tmp.back();
            tmp.pop_back();
            block.back().emplace_back(edge);
            if constexpr (IS_FULL_VER) {
              st.emplace(edge.first);
              st.emplace(edge.second);
            }
            if (edge.first == src && edge.second == dst) break;
          }
          if constexpr (IS_FULL_VER) {
            vertices.emplace_back();
            for (const int el : st) {
              vertices.back().emplace_back(el);
              if (is_articulation_point[el]) {
                cutpoint[el].emplace_back(idx);
              } else {
                id[el] = idx;
              }
            }
          }
        }
      }
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_BICONNECTED_COMPONENT_HPP_
