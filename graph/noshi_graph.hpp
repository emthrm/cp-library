#pragma once
#include <vector>
#include "edge.hpp"

template <typename CostType>
struct NoshiGraph {
  std::vector<std::vector<Edge<CostType>>> graph;

  NoshiGraph(int n) {
    while (p2 < n) p2 <<= 1;
    int doub = p2 << 1, half = p2 >> 1;
    graph.resize(doub + p2);
    for (int i = 1; i < half; ++i) {
      graph[i + p2].emplace_back(i + p2, (i << 1) + p2, 0);
      graph[i + p2].emplace_back(i + p2, (i << 1) + p2 + 1, 0);
      graph[(i << 1) + doub].emplace_back((i << 1) + doub, i + doub, 0);
      graph[(i << 1) + doub + 1].emplace_back((i << 1) + doub + 1, i + doub, 0);
    }
    for (int src = p2 + half, dst = 0; dst < p2; ++src, dst += 2) {
      graph[src].emplace_back(src, dst, 0);
      graph[src].emplace_back(src, dst + 1, 0);
    }
    for (int src = doub + half, dst = 0; dst < p2; ++src, dst += 2) {
      graph[dst].emplace_back(dst, src, 0);
      graph[dst + 1].emplace_back(dst + 1, src, 0);
    }
  }

  void add_edge(int src, int dst, CostType cost) {
    graph[src].emplace_back(src, dst, cost);
  }

  void add_edge(int src_l, int src_r, int dst_l, int dst_r, CostType cost) {
    if (src_r <= src_l || dst_r <= dst_l) return;
    int src_id = graph.size(), dst_id = src_id + 1;
    graph.resize(graph.size() + 2);
    if ((dst_l += p2) & 1) graph[dst_id].emplace_back(dst_id, dst_l++ - p2, 0);
    if ((dst_r += p2) & 1) graph[dst_id].emplace_back(dst_id, --dst_r - p2, 0);
    for (dst_l >>= 1, dst_r >>= 1; dst_l < dst_r; dst_l >>= 1, dst_r >>= 1) {
      if (dst_l & 1) graph[dst_id].emplace_back(dst_id, dst_l++ + p2, 0);
      if (dst_r & 1) graph[dst_id].emplace_back(dst_id, --dst_r + p2, 0);
    }
    graph[src_id].emplace_back(src_id, dst_id, cost);
    if ((src_l += p2) & 1) {
      int src = src_l++ - p2;
      graph[src].emplace_back(src, src_id, 0);
    }
    if ((src_r += p2) & 1) {
      int src = --src_r - p2;
      graph[src].emplace_back(src, src_id, 0);
    }
    for (src_l >>= 1, src_r >>= 1; src_l < src_r; src_l >>= 1, src_r >>= 1) {
      if (src_l & 1) {
        int src = src_l++ + (p2 << 1);
        graph[src].emplace_back(src, src_id, 0);
      }
      if (src_r & 1) {
        int src = --src_r + (p2 << 1);
        graph[src].emplace_back(src, src_id, 0);
      }
    }
  }

private:
  int p2 = 1;
};
