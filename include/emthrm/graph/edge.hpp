/**
 * @brief 辺
 */

#ifndef EMTHRM_GRAPH_EDGE_HPP_
#define EMTHRM_GRAPH_EDGE_HPP_


namespace emthrm {

template <typename CostType>
struct Edge {
  int src, dst;
  CostType cost;
  explicit Edge(const int src, const int dst, const CostType cost = 0)
      : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge& x) const {
    if (cost != x.cost) return cost < x.cost;
    return src != x.src ? src < x.src : dst < x.dst;
  }
  inline bool operator<=(const Edge& x) const { return !(x < *this); }
  inline bool operator>(const Edge& x) const { return x < *this; }
  inline bool operator>=(const Edge& x) const { return !(*this < x); }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_EDGE_HPP_
