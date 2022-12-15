#ifndef EMTHRM_GRAPH_BICONNECTED_COMPONENT_HPP_
#define EMTHRM_GRAPH_BICONNECTED_COMPONENT_HPP_

// #include <algorithm>
#include <set>
#include <utility>
#include <vector>

#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/lowlink.hpp"

namespace emthrm {

template <typename CostType>
struct BiconnectedComponent : Lowlink<CostType> {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, cutpoint;
  std::vector<std::vector<Edge<CostType>>> block;

  explicit BiconnectedComponent(
      const std::vector<std::vector<Edge<CostType>>>& graph,
      const bool is_full_ver = false)
      : Lowlink<CostType>(graph), is_full_ver(is_full_ver) {
    const int n = graph.size();
    id.assign(n, -2);
    if (is_full_ver) {
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
    // if (is_full_ver) {
    //   for (int i = 0; i < m; ++i) {
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    //   for (int i = 0; i < n; ++i) {
    //     std::sort(cutpoint[i].begin(), cutpoint[i].end());
    //   }
    // }
  }

 private:
  const bool is_full_ver;
  std::vector<bool> is_articulation_point;
  std::vector<Edge<CostType>> tmp;

  void dfs(const int par, const int ver) {
    id[ver] = -1;
    for (const Edge<CostType>& e : this->graph[ver]) {
      if (e.dst == par) continue;
      int src = ver, dst = e.dst;
      if (src > dst) std::swap(src, dst);
      if (id[e.dst] == -2 || this->order[e.dst] < this->order[ver]) {
        tmp.emplace_back(src, dst, e.cost);
      }
      if (id[e.dst] == -2) {
        dfs(ver, e.dst);
        if (this->lowlink[e.dst] >= this->order[ver]) {
          const int idx = block.size();
          block.emplace_back();
          std::set<int> st;
          while (true) {
            const Edge<CostType> edge = tmp.back();
            tmp.pop_back();
            block.back().emplace_back(edge);
            if (is_full_ver) {
              st.emplace(edge.src);
              st.emplace(edge.dst);
            }
            if (edge.src == src && edge.dst == dst) break;
          }
          if (is_full_ver) {
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

#endif  // EMTHRM_GRAPH_BICONNECTED_COMPONENT_HPP_
