#pragma once
#include <cassert>
#include <iterator>
#include <queue>
#include <vector>

#include "edge.hpp"

template <typename CostType>
struct UnicyclicGraph {
  std::vector<bool> is_in_loop;
  std::vector<int> belong, mapping;
  std::vector<Edge<CostType>> loop;
  std::vector<std::vector<int>> invs;
  std::vector<std::vector<std::vector<Edge<CostType>>>> forest;

  explicit UnicyclicGraph(const int n)
      : n(n), is_in_loop(n, false), belong(n, -1), mapping(n, -1), graph(n) {}

  void add_edge(const int src, const int dst, const CostType cost = 0) {
    const int id = srcs.size();
    srcs.emplace_back(src);
    dsts.emplace_back(dst);
    costs.emplace_back(cost);
    graph[src].emplace_back(id);
    if (dst != src) graph[dst].emplace_back(id);
  }

  void build() {
    dfs(-1, 0);
    std::queue<int> que;
    for (const Edge<CostType>& e : loop) {
      const int root = e.src, forest_id = forest.size();
      belong[root] = forest_id;
      mapping[root] = 0;
      std::vector<int> inv{root};
      std::vector<std::vector<Edge<CostType>>> tree(1);
      que.emplace(root);
      while (!que.empty()) {
        const int ver = que.front();
        que.pop();
        for (const int id : graph[ver]) {
          const int dst = destination(id, ver);
          if (belong[dst] == -1 && !is_in_loop[dst]) {
            const int idx = tree.size();
            belong[dst] = forest_id;
            mapping[dst] = idx;
            inv.emplace_back(dst);
            tree[mapping[ver]].emplace_back(mapping[ver], idx, costs[id]);
            tree.emplace_back(std::vector<Edge<CostType>>{
                Edge<CostType>(idx, mapping[ver], costs[id])});
            que.emplace(dst);
          }
        }
      }
      if (inv.size() == 1) {
        belong[root] = mapping[root] = -1;
      } else {
        invs.emplace_back(inv);
        forest.emplace_back(tree);
      }
    }
  }

 private:
  const int n;
  std::vector<int> srcs, dsts;
  std::vector<CostType> costs;
  std::vector<std::vector<int>> graph;

  int destination(const int id, const int s) const {
    return (srcs[id] == s ? dsts : srcs)[id];
  }

  bool dfs(const int prev_id, const int ver) {
    is_in_loop[ver] = true;
    for (const int id : graph[ver]) {
      if (id == prev_id) continue;
      const int dst = destination(id, ver);
      loop.emplace_back(ver, dst, costs[id]);
      if (is_in_loop[dst]) {
        for (int i = loop.size() - 1; i >= 0; --i) {
          if (loop[i].src == dst) {
            for (int j = 0; j < i; ++j) {
              is_in_loop[loop[j].src] = false;
            }
            loop.erase(loop.begin(), std::next(loop.begin(), i));
            return true;
          }
        }
        assert(false);
      }
      if (dfs(id, dst)) return true;
      loop.pop_back();
    }
    is_in_loop[ver] = false;
    return false;
  }
};
