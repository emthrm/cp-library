/**
 * @title 辺
 */

#ifndef EMTHRM_GRAPH_EDGE_HPP_
#define EMTHRM_GRAPH_EDGE_HPP_

#include <compare>

namespace emthrm {

template <typename CostType>
struct Edge {
  CostType cost;
  int src, dst;

  explicit Edge(const int src, const int dst, const CostType cost = 0)
      : cost(cost), src(src), dst(dst) {}

  auto operator<=>(const Edge& x) const = default;
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_EDGE_HPP_
