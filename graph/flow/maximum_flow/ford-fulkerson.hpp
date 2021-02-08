/**
 * @brief Ford-Fulkerson 法
 * @docs docs/graph/flow/maximum_flow/maximum_flow.md
 */

#pragma once
#include <algorithm>
#include <vector>

template <typename T>
struct FordFulkerson {
  struct Edge {
    int dst, rev;
    T cap;
    Edge(int dst, T cap, int rev) : dst(dst), cap(cap), rev(rev) {}
  };

  std::vector<std::vector<Edge>> graph;

  FordFulkerson(int n) : graph(n), used(n, -1) {}

  void add_edge(int src, int dst, T cap) {
    graph[src].emplace_back(dst, cap, graph[dst].size());
    graph[dst].emplace_back(src, 0, graph[src].size() - 1);
  }

  T maximum_flow(int s, int t, T limit) {
    T res = 0;
    while (true) {
      T tmp = dfs(s, t, limit);
      ++timestamp;
      if (tmp == 0) return res;
      res += tmp;
      limit -= tmp;
    }
  }

private:
  std::vector<int> used;
  int timestamp = 0;

  T dfs(int ver, int t, T flow) {
    if (ver == t) return flow;
    used[ver] = timestamp;
    for (Edge &e : graph[ver]) {
      if (used[e.dst] < timestamp && e.cap > 0) {
        T tmp = dfs(e.dst, t, std::min(flow, e.cap));
        if (tmp > 0) {
          e.cap -= tmp;
          graph[e.dst][e.rev].cap += tmp;
          return tmp;
        }
      }
    }
    return 0;
  }
};
