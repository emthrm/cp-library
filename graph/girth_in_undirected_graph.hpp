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

#include "./edge.hpp"

template <typename CostType>
CostType girth_in_undirected_graph(
    const int n, const std::vector<Edge<CostType>>& edges,
    const CostType inf = std::numeric_limits<CostType>::max()) {
  const int m = edges.size();
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    graph[edges[i].src].emplace_back(i);
    graph[edges[i].dst].emplace_back(i);
  }
  std::vector<bool> is_used(m, false);
  std::vector<int> label(n), prev(n);
  std::vector<CostType> dist(n);
  std::priority_queue<std::pair<CostType, int>,
                      std::vector<std::pair<CostType, int>>,
                      std::greater<std::pair<CostType, int>>> que;
  CostType res = inf;
  for (int root = 0; root < n; ++root) {
    std::fill(is_used.begin(), is_used.end(), false);
    std::fill(label.begin(), label.end(), -2);
    label[root] = -1;
    std::fill(prev.begin(), prev.end(), -1);
    std::fill(dist.begin(), dist.end(), inf);
    dist[root] = 0;
    que.emplace(0, root);
    while (!que.empty()) {
      CostType d;
      int ver;
      std::tie(d, ver) = que.top();
      que.pop();
      if (d > dist[ver]) continue;
      for (const int id : graph[ver]) {
        const int dst = (edges[id].src == ver ? edges[id].dst : edges[id].src);
        const CostType nxt = dist[ver] + edges[id].cost;
        if (nxt < dist[dst]) {
          dist[dst] = nxt;
          label[dst] = (label[ver] == -1 ? dst : label[ver]);
          if (prev[dst] != -1) is_used[dst] = true;
          is_used[id] = true;
          que.emplace(nxt, dst);
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      const int src = edges[i].src, dst = edges[i].dst;
      if (!is_used[i] && label[src] != -2 && label[dst] != -2) {
        if (label[src] != label[dst]) {
          res = std::min(res, dist[src] + dist[dst] + edges[i].cost);
        } else if (label[src] == -1) {
          res = std::min(res, edges[i].cost);
        }
      }
    }
  }
  return res;
}
