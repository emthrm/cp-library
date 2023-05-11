#ifndef EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_TECHNIQUE_HPP_
#define EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_TECHNIQUE_HPP_

#include <algorithm>
#include <utility>
#include <vector>

#include "emthrm/data_structure/sparse_table.hpp"
#include "emthrm/graph/edge.hpp"
#include "emthrm/graph/tree/euler_tour_technique.hpp"

namespace emthrm {

template <typename CostType>
struct LowestCommonAncestor : EulerTourTechnique<CostType> {
  explicit LowestCommonAncestor(
      const std::vector<std::vector<Edge<CostType>>>& graph,
      const int root = 0)
      : EulerTourTechnique<CostType>(graph, root) {
    const int n = this->preorder.size();
    std::vector<std::pair<int, int>> nodes(n);
    for (int i = 0; i < n; ++i) {
      nodes[i] = {this->depth[i], this->preorder[i]};
    }
    sparse_table.init(
        nodes,
        [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            -> std::pair<int, int> {
          return std::min(a, b);
        });
  }

  int query(int u, int v) const {
    u = this->left[u];
    v = this->left[v];
    if (u > v) std::swap(u, v);
    return sparse_table.query(u, v + 1).second;
  }

 private:
  SparseTable<std::pair<int, int>> sparse_table;
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_TECHNIQUE_HPP_
