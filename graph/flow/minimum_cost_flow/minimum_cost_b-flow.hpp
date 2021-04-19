/**
 * @brief 最小費用 $\bm{b}$-フロー 最短路反復法版
 * @docs docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md
 */

#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

template <typename T, typename U>
struct MinimumCostBFlow {
  struct Edge {
    int dst, rev;
    T cap;
    U cost;
    Edge(int dst, T cap, U cost, int rev) : dst(dst), cap(cap), cost(cost), rev(rev) {}
  };

  const U uinf;
  std::vector<std::vector<Edge>> graph;

  MinimumCostBFlow(int n, const U uinf = std::numeric_limits<U>::max())
  : n(n), uinf(uinf), graph(n + 2), b(n + 2, 0) {}

  void add_edge(int src, int dst, T cap, U cost) {
    if (cost < 0) {
      b[src] -= cap;
      b[dst] += cap;
      res += cost * cap;
      std::swap(src, dst);
      cost = -cost;
    }
    graph[src].emplace_back(dst, cap, cost, graph[dst].size());
    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);
  }

  void supply_or_demand(int ver, T amount) { b[ver] += amount; }

  U solve() {
    assert(std::accumulate(b.begin(), b.end(), T(0)) == 0);
    T flow = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] > 0) {
        add_edge(n, i, b[i], 0);
        flow += b[i];
      } else if (b[i] < 0) {
        add_edge(i, n + 1, -b[i], 0);
      }
    }
    std::vector<int> prev_v(n + 2, -1), prev_e(n + 2, -1);
    std::vector<U> dist(n + 2), potential(n + 2, 0);
    std::priority_queue<std::pair<U, int>, std::vector<std::pair<U, int>>, std::greater<std::pair<U, int>>> que;
    while (flow > 0) {
      std::fill(dist.begin(), dist.end(), uinf);
      dist[n] = 0;
      que.emplace(0, n);
      while (!que.empty()) {
        U fst; int ver; std::tie(fst, ver) = que.top(); que.pop();
        if (dist[ver] < fst) continue;
        for (int i = 0; i < graph[ver].size(); ++i) {
          const Edge &e = graph[ver][i];
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

  U solve(int s, int t, T flow) {
    supply_or_demand(s, flow);
    supply_or_demand(t, -flow);
    return solve();
  }

private:
  int n;
  U res = 0;
  std::vector<T> b;
};
