/**
 * @brief 主双対法2
 * @docs docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md
 */

#pragma once
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

template <typename T, typename U>
struct PrimalDual2 {
  struct Edge {
    int dst, rev;
    T cap;
    U cost;
    Edge(int dst, T cap, U cost, int rev) : dst(dst), cap(cap), cost(cost), rev(rev) {}
  };

  const U uinf;
  std::vector<std::vector<Edge>> graph;

  PrimalDual2(int n, const U uinf = std::numeric_limits<U>::max()) : n(n), uinf(uinf), graph(n + 2), d(n + 2, 0) {}

  void add_edge(int src, int dst, T cap, U cost) {
    if (cost < 0) {
      d[src] -= cap;
      d[dst] += cap;
      res += cost * cap;
      std::swap(src, dst);
      cost = -cost;
    }
    graph[src].emplace_back(dst, cap, cost, graph[dst].size());
    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);
  }

  U minimum_cost_flow() {
    T flow = 0;
    for (int i = 0; i < n; ++i) {
      if (d[i] > 0) {
        add_edge(n, i, d[i], 0);
        flow += d[i];
      } else if (d[i] < 0) {
        add_edge(i, n + 1, -d[i], 0);
      }
    }
    std::vector<int> prev_v(n + 2, -1), prev_e(n + 2, -1);
    std::vector<U> potential(n + 2, 0), dist(n + 2);
    std::priority_queue<Pui, std::vector<Pui>, std::greater<Pui>> que;
    while (flow > 0) {
      std::fill(dist.begin(), dist.end(), uinf);
      dist[n] = 0;
      que.emplace(0, n);
      while (!que.empty()) {
        U fst; int ver; std::tie(fst, ver) = que.top(); que.pop();
        if (dist[ver] < fst) continue;
        for (int i = 0; i < graph[ver].size(); ++i) {
          Edge &e = graph[ver][i];
          U nx = dist[ver] + e.cost + potential[ver] - potential[e.dst];
          if (e.cap > 0 && dist[e.dst] > nx) {
            dist[e.dst] = nx;
            prev_v[e.dst] = ver;
            prev_e[e.dst] = i;
            que.emplace(dist[e.dst], e.dst);
          }
        }
      }
      if (dist[n + 1] == uinf) return uinf;
      for (int i = 0; i < n + 2; ++i) {
        if (dist[i] != uinf) potential[i] += dist[i];
      }
      T f = flow;
      for (int v = n + 1; v != n; v = prev_v[v]) {
        if (graph[prev_v[v]][prev_e[v]].cap < f) f = graph[prev_v[v]][prev_e[v]].cap;
      }
      flow -= f;
      res += potential[n + 1] * f;
      for (int v = n + 1; v != n; v = prev_v[v]) {
        Edge &e = graph[prev_v[v]][prev_e[v]];
        e.cap -= f;
        graph[v][e.rev].cap += f;
      }
    }
    return res;
  }

  U minimum_cost_flow(int s, int t, T flow) {
    d[s] += flow;
    d[t] -= flow;
    return minimum_cost_flow();
  }

private:
  using Pui = std::pair<U, int>;

  int n;
  U res = 0;
  std::vector<T> d;
};
