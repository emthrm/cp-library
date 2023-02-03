/**
 * @brief Dinic 法
 * @docs docs/graph/flow/maximum_flow/maximum_flow.md
 */

#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_DINIC_HPP_
#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_DINIC_HPP_

#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace emthrm {

template <typename T>
struct Dinic {
  struct Edge {
    int dst, rev;
    T cap;
    explicit Edge(const int dst, const T cap, const int rev)
        : dst(dst), rev(rev), cap(cap) {}
  };

  std::vector<std::vector<Edge>> graph;

  explicit Dinic(const int n) : graph(n), level(n), itr(n) {}

  void add_edge(const int src, const int dst, const T cap) {
    graph[src].emplace_back(dst, cap, graph[dst].size());
    graph[dst].emplace_back(src, 0, graph[src].size() - 1);
  }

  T maximum_flow(const int s, const int t,
                 T limit = std::numeric_limits<T>::max()) {
    T res = 0;
    while (limit > 0) {
      std::fill(level.begin(), level.end(), -1);
      level[s] = 0;
      std::queue<int> que;
      que.emplace(s);
      while (!que.empty()) {
        const int ver = que.front();
        que.pop();
        for (const Edge& e : graph[ver]) {
          if (level[e.dst] == -1 && e.cap > 0) {
            level[e.dst] = level[ver] + 1;
            que.emplace(e.dst);
          }
        }
      }
      if (level[t] == -1) break;
      std::fill(itr.begin(), itr.end(), 0);
      while (limit > 0) {
        const T f = dfs(s, t, limit);
        if (f == 0) break;
        limit -= f;
        res += f;
      }
    }
    return res;
  }

 private:
  std::vector<int> level, itr;

  T dfs(const int ver, const int t, const T flow) {
    if (ver == t) return flow;
    for (; std::cmp_less(itr[ver], graph[ver].size()); ++itr[ver]) {
      Edge& e = graph[ver][itr[ver]];
      if (level[ver] < level[e.dst] && e.cap > 0) {
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

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_DINIC_HPP_
