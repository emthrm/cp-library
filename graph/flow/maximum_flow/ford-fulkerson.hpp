/**
 * @brief Ford-Fulkerson 法
 * @docs docs/graph/flow/maximum_flow/maximum_flow.md
 */

#pragma once
#include <algorithm>
#include <limits>
#include <vector>

template <typename T>
struct FordFulkerson {
  struct Edge {
    int dst, rev;
    T cap;
    explicit Edge(const int dst, const T cap, const int rev)
        : dst(dst), cap(cap), rev(rev) {}
  };

  std::vector<std::vector<Edge>> graph;

  explicit FordFulkerson(const int n)
      : graph(n), timestamp(0), is_used(n, -1) {}

  void add_edge(const int src, const int dst, const T cap) {
    graph[src].emplace_back(dst, cap, graph[dst].size());
    graph[dst].emplace_back(src, 0, graph[src].size() - 1);
  }

  T maximum_flow(const int s, const int t,
                 T limit = std::numeric_limits<T>::max()) {
    T res = 0;
    while (limit > 0) {
      const T tmp = dfs(s, t, limit);
      ++timestamp;
      if (tmp == 0) break;
      limit -= tmp;
      res += tmp;
    }
    return res;
  }

 private:
  int timestamp;
  std::vector<int> is_used;

  T dfs(const int ver, const int t, const T flow) {
    if (ver == t) return flow;
    is_used[ver] = timestamp;
    for (Edge& e : graph[ver]) {
      if (is_used[e.dst] < timestamp && e.cap > 0) {
        const T tmp = dfs(e.dst, t, std::min(flow, e.cap));
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
