/**
 * @brief Dinic 法
 * @docs docs/graph/flow/maximum_flow/maximum_flow.md
 */

#pragma once
#include <algorithm>
#include <queue>
#include <vector>

template <typename T>
struct Dinic {
  struct Edge {
    int dst, rev;
    T cap;
    Edge(int dst, T cap, int rev) : dst(dst), cap(cap), rev(rev) {}
  };

  std::vector<std::vector<Edge>> graph;

  Dinic(int n) : graph(n), level(n), itr(n) {}

  void add_edge(int src, int dst, T cap) {
    graph[src].emplace_back(dst, cap, graph[dst].size());
    graph[dst].emplace_back(src, 0, graph[src].size() - 1);
  }

  T maximum_flow(int s, int t, T limit) {
    T res = 0;
    while (true) {
      bfs(s);
      if (level[t] == -1) return res;
      std::fill(itr.begin(), itr.end(), 0);
      T tmp;
      while ((tmp = dfs(s, t, limit)) > 0) res += tmp;
    }
  }

private:
  std::vector<int> level, itr;

  void bfs(int s) {
    std::fill(level.begin(), level.end(), -1);
    std::queue<int> que;
    level[s] = 0;
    que.emplace(s);
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (const Edge &e : graph[ver]) {
        if (level[e.dst] == -1 && e.cap > 0) {
          level[e.dst] = level[ver] + 1;
          que.emplace(e.dst);
        }
      }
    }
  }

  T dfs(int ver, int t, T flow) {
    if (ver == t) return flow;
    for (; itr[ver] < graph[ver].size(); ++itr[ver]) {
      Edge &e = graph[ver][itr[ver]];
      if (level[ver] < level[e.dst] && e.cap > 0) {
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
