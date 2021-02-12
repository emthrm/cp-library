/**
 * @brief 主双対法
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
struct PrimalDual {
  struct Edge {
    int dst, rev;
    T cap;
    U cost;
    Edge(int dst, T cap, U cost, int rev) : dst(dst), cap(cap), cost(cost), rev(rev) {}
  };

  const U uinf;
  std::vector<std::vector<Edge>> graph;

  PrimalDual(int n, const U uinf = std::numeric_limits<U>::max())
  : n(n), uinf(uinf), graph(n), prev_v(n, -1), prev_e(n, -1), potential(n, 0), dist(n) {}

  void add_edge(int src, int dst, T cap, U cost) {
    has_negative_edge |= cost < 0;
    graph[src].emplace_back(dst, cap, cost, graph[dst].size());
    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);
  }

  U minimum_cost_flow(int s, int t, T flow) {
    U res = 0;
    if (has_negative_edge) {
      bellman_ford(s);
      if (dist[t] == uinf) return uinf;
      res += calc(s, t, flow);
    }
    while (flow > 0) {
      dijkstra(s);
      if (dist[t] == uinf) return uinf;
      res += calc(s, t, flow);
    }
    return res;
  }

  U minimum_cost_flow(int s, int t) {
    U res = 0;
    bellman_ford(s);
    if (potential[t] >= 0 || dist[t] == uinf) return res;
    T tmp = tinf;
    res += calc(s, t, tmp);
    while (true) {
      dijkstra(s);
      if (potential[t] >= 0 || dist[t] == uinf) return res;
      res += calc(s, t, tmp);
    }
  }

  std::pair<T, U> min_cost_max_flow(int s, int t, T flow) {
    T mx = flow;
    U cost = 0;
    if (has_negative_edge) {
      bellman_ford(s);
      if (dist[t] == uinf) return {mx - flow, cost};
      cost += calc(s, t, flow);
    }
    while (flow > 0) {
      dijkstra(s);
      if (dist[t] == uinf) return {mx - flow, cost};
      cost += calc(s, t, flow);
    }
    return {mx - flow, cost};
  }

private:
  using Pui = std::pair<U, int>;

  int n;
  const T tinf = std::numeric_limits<T>::max();
  bool has_negative_edge = false;
  std::vector<int> prev_v, prev_e;
  std::vector<U> potential, dist;
  std::priority_queue<Pui, std::vector<Pui>, std::greater<Pui>> que;

  void bellman_ford(int s) {
    std::fill(dist.begin(), dist.end(), uinf);
    dist[s] = 0;
    bool is_updated = true;
    for (int step = 0; step < n; ++step) {
      is_updated = false;
      for (int i = 0; i < n; ++i) {
        if (dist[i] == uinf) continue;
        for (int j = 0; j < graph[i].size(); ++j) {
          Edge e = graph[i][j];
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
      Pui pr = que.top(); que.pop();
      int ver = pr.second;
      if (dist[ver] < pr.first) continue;
      for (int i = 0; i < graph[ver].size(); ++i) {
        Edge e = graph[ver][i];
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
