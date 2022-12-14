#pragma once
#include <vector>

#include "emthrm/graph/edge.hpp"

template <typename CostType>
struct NoshiGraph {
  std::vector<std::vector<Edge<CostType>>> graph;

  explicit NoshiGraph(const int n) : p2(1) {
    while (p2 < n) p2 <<= 1;
    const int dbl = p2 << 1, hlf = p2 >> 1;
    graph.resize(dbl + p2);
    for (int i = 1; i < hlf; ++i) {
      add_edge(i + p2, (i << 1) + p2);
      add_edge(i + p2, (i << 1) + 1 + p2);
      add_edge((i << 1) + dbl, i + dbl);
      add_edge((i << 1) + 1 + dbl, i + dbl);
    }
    for (int src = p2 + hlf, dst = 0; dst < p2; ++src, dst += 2) {
      add_edge(src, dst);
      add_edge(src, dst + 1);
    }
    for (int src = 0, dst = dbl + hlf; src < p2; src += 2, ++dst) {
      add_edge(src, dst);
      add_edge(src + 1, dst);
    }
  }

  void add_edge(const int src, const int dst, const CostType cost = 0) {
    graph[src].emplace_back(src, dst, cost);
  }

  void add_edge(int src_l, int src_r, int dst_l, int dst_r,
                const CostType cost) {
    if (src_r <= src_l || dst_r <= dst_l) return;
    const int src_id = graph.size(), dst_id = src_id + 1;
    graph.emplace_back();
    graph.emplace_back();
    if ((dst_l += p2) & 1) add_edge(dst_id, dst_l++ - p2);
    if ((dst_r += p2) & 1) add_edge(dst_id, --dst_r - p2);
    for (dst_l >>= 1, dst_r >>= 1; dst_l < dst_r; dst_l >>= 1, dst_r >>= 1) {
      if (dst_l & 1) add_edge(dst_id, dst_l++ + p2);
      if (dst_r & 1) add_edge(dst_id, --dst_r + p2);
    }
    add_edge(src_id, dst_id, cost);
    if ((src_l += p2) & 1) add_edge(src_l++ - p2, src_id);
    if ((src_r += p2) & 1) add_edge(--src_r - p2, src_id);
    for (src_l >>= 1, src_r >>= 1; src_l < src_r; src_l >>= 1, src_r >>= 1) {
      if (src_l & 1) add_edge(src_l++ + (p2 << 1), src_id);
      if (src_r & 1) add_edge(--src_r + (p2 << 1), src_id);
    }
  }

 private:
  int p2;
};
