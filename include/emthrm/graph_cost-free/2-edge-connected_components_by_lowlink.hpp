#ifndef EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_
#define EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_

// #include <algorithm>
#include <utility>
#include <vector>

#include "emthrm/graph_cost-free/lowlink.hpp"

namespace emthrm {

struct TwoEdgeConnectedComponents : Lowlink {
  std::vector<int> id;
  std::vector<std::vector<int>> vertices, g;

  TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& graph,
                             const bool is_full_ver = false)
      : Lowlink(graph), is_full_ver(is_full_ver) {
    const int n = graph.size();
    id.assign(n, -1);
    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (id[i] == -1) dfs(-1, i, &m);
    }
    g.resize(m);
#if __cplusplus >= 201703L
    for (const auto& [s, t] : this->bridges) {
      const int u = id[s], v = id[t];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
#else
    for (const std::pair<int, int>& e : this->bridges) {
      const int u = id[e.first], v = id[e.second];
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
#endif
    // if (is_full_ver) {
    //   for (int i = 0; i < m; ++i) {
    //     std::sort(vertices[i].begin(), vertices[i].end());
    //   }
    // }
  }

 private:
  const bool is_full_ver;

  void dfs(const int par, const int ver, int* m) {
    if (par != -1 && this->order[par] >= this->lowlink[ver]) {
      id[ver] = id[par];
    } else {
      id[ver] = (*m)++;
      if (is_full_ver) vertices.emplace_back();
    }
    if (is_full_ver) vertices[id[ver]].emplace_back(ver);
    for (const int e : this->graph[ver]) {
      if (id[e] == -1) dfs(ver, e, m);
    }
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_COST_FREE_2_EDGE_CONNECTED_COMPONENTS_BY_LOWLINK_HPP_
