/**
 * @brief 内周 無向グラフ版
 * @docs docs/graph/girth.md
 */

#pragma once
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include "edge.hpp"

template <typename CostType>
CostType girth_in_undirected_graph(int n, const std::vector<Edge<CostType>> &edges,
                                   const CostType inf = std::numeric_limits<CostType>::max()) {
  int m = edges.size();
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    graph[edges[i].src].emplace_back(i);
    graph[edges[i].dst].emplace_back(i);
  }
  std::vector<bool> used(m, false);
  std::vector<CostType> dist(n);
  std::vector<int> label(n), prev(n);
  using Pci = std::pair<CostType, int>;
  std::priority_queue<Pci, std::vector<Pci>, std::greater<Pci>> que;
  CostType res = inf;
  for (int root = 0; root < n; ++root) {
    std::fill(used.begin(), used.end(), false);
    std::fill(dist.begin(), dist.end(), inf);
    dist[root] = 0;
    std::fill(label.begin(), label.end(), -2);
    label[root] = -1;
    std::fill(prev.begin(), prev.end(), -1);
    que.emplace(0, root);
    while (!que.empty()) {
      CostType c; int ver; std::tie(c, ver) = que.top(); que.pop();
      if (dist[ver] < c) continue;
      for (int id : graph[ver]) {
        int dst = edges[id].src == ver ? edges[id].dst : edges[id].src;
        CostType cost = dist[ver] + edges[id].cost;
        if (cost < dist[dst]) {
          dist[dst] = cost;
          label[dst] = label[ver] == -1 ? dst : label[ver];
          if (prev[dst] != -1) used[dst] = true;
          used[id] = true;
          que.emplace(cost, dst);
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      int src = edges[i].src, dst = edges[i].dst;
      CostType cost = edges[i].cost;
      if (!used[i] && label[src] != -2 && label[dst] != -2) {
        if (label[src] != label[dst]) {
          CostType loop = dist[src] + dist[dst] + cost;
          if (loop < res) res = loop;
        } else if (label[src] == -1) {
          if (cost < res) res = cost;
        }
      }
    }
  }
  return res;
}
