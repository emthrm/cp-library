/**
 * @brief 最小費用 $s$-$t$-フロー 最短路反復法版
 * @docs docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md
 */

#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template <typename T, typename U>
struct MinimumCostSTFlow {
  struct Edge {
    int dst, rev;
    T cap;
    U cost;
    Edge(int dst, T cap, U cost, int rev) : dst(dst), cap(cap), cost(cost), rev(rev) {}
  };

  const U uinf;
  std::vector<std::vector<Edge>> graph;

  MinimumCostSTFlow(int n, const U uinf = std::numeric_limits<U>::max())
  : n(n), uinf(uinf), graph(n), prev_v(n, -1), prev_e(n, -1), dist(n), potential(n, 0) {}

  void add_edge(int src, int dst, T cap, U cost) {
    has_negative_edge |= cost < 0;
    graph[src].emplace_back(dst, cap, cost, graph[dst].size());
    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);
  }

  U solve(int s, int t, T flow) {
    U res = 0;
    while (flow > 0) {
      if (has_negative_edge) {
        bellman_ford(s);
        has_negative_edge = false;
      } else {
        dijkstra(s);
      }
      if (dist[t] == uinf) return uinf;
      res += calc(s, t, flow);
    }
    return res;
  }

  U solve(int s, int t) {
    U res = 0;
    T f = tinf;
    bool init = false;
    while (true) {
      if (init) {
        dijkstra(s);
      } else {
        bellman_ford(s);
        init = true;
      }
      if (potential[t] >= 0 || dist[t] == uinf) return res;
      res += calc(s, t, f);
    }
  }

  std::pair<T, U> minimum_cost_maximum_flow(int s, int t, T flow) {
    T f = flow;
    U cost = 0;
    while (flow > 0) {
      if (has_negative_edge) {
        bellman_ford(s);
        has_negative_edge = false;
      } else {
        dijkstra(s);
      }
      if (dist[t] == uinf) return {f - flow, cost};
      cost += calc(s, t, flow);
    }
    return {f, cost};
  }

private:
  const T tinf = std::numeric_limits<T>::max();
  int n;
  bool has_negative_edge = false;
  std::vector<int> prev_v, prev_e;
  std::vector<U> dist, potential;
  std::priority_queue<std::pair<U, int>, std::vector<std::pair<U, int>>, std::greater<std::pair<U, int>>> que;

  void bellman_ford(int s) {
    std::fill(dist.begin(), dist.end(), uinf);
    dist[s] = 0;
    bool is_updated = true;
    for (int step = 0; step < n; ++step) {
      is_updated = false;
      for (int i = 0; i < n; ++i) {
        if (dist[i] == uinf) continue;
        for (int j = 0; j < graph[i].size(); ++j) {
          const Edge &e = graph[i][j];
          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {
            dist[e.dst] = dist[i] + e.cost;
            prev_v[e.dst] = i;
            prev_e[e.dst] = j;
            is_updated = true;
          }
        }
      }
      if (!is_updated) break;
    }
    assert(!is_updated);
    for (int i = 0; i < n; ++i) {
      if (dist[i] != uinf) potential[i] += dist[i];
    }
  }

  void dijkstra(int s) {
    std::fill(dist.begin(), dist.end(), uinf);
    dist[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
      std::pair<U, int> pr = que.top(); que.pop();
      int ver = pr.second;
      if (dist[ver] < pr.first) continue;
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
    for (int i = 0; i < n; ++i) {
      if (dist[i] != uinf) potential[i] += dist[i];
    }
  }

  U calc(int s, int t, T &flow) {
    T f = flow;
    for (int v = t; v != s; v = prev_v[v]) f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);
    flow -= f;
    for (int v = t; v != s; v = prev_v[v]) {
      Edge &e = graph[prev_v[v]][prev_e[v]];
      e.cap -= f;
      graph[v][e.rev].cap += f;
    }
    return potential[t] * f;
  }
};
