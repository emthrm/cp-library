/**
 * @brief 最小費用 $s$-$t$-フロー 最短路反復法版
 * @docs docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md
 */

#ifndef EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_S_T_FLOW_HPP_
#define EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_S_T_FLOW_HPP_

#include <algorithm>
#include <cassert>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

namespace emthrm {

template <typename T, typename U>
struct MinimumCostSTFlow {
  struct Edge {
    int dst, rev;
    T cap;
    U cost;
    explicit Edge(const int dst, const T cap, const U cost, const int rev)
        : dst(dst), rev(rev), cap(cap), cost(cost) {}
  };

  const U uinf;
  std::vector<std::vector<Edge>> graph;

  explicit MinimumCostSTFlow(const int n,
                             const U uinf = std::numeric_limits<U>::max())
      : uinf(uinf), graph(n), tinf(std::numeric_limits<T>::max()), n(n),
        has_negative_edge(false), prev_v(n, -1), prev_e(n, -1), dist(n),
        potential(n, 0) {}

  void add_edge(const int src, const int dst, const T cap, const U cost) {
    has_negative_edge |= cost < 0;
    graph[src].emplace_back(dst, cap, cost, graph[dst].size());
    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);
  }

  U solve(const int s, const int t, T flow) {
    if (flow == 0) return 0;
    U res = 0;
    has_negative_edge ? bellman_ford(s) : dijkstra(s);
    while (true) {
      if (dist[t] == uinf) return uinf;
      res += calc(s, t, &flow);
      if (flow == 0) break;
      dijkstra(s);
    }
    return res;
  }

  U solve(const int s, const int t) {
    U res = 0;
    T flow = tinf;
    bellman_ford(s);
    while (potential[t] < 0 && dist[t] != uinf) {
      res += calc(s, t, &flow);
      dijkstra(s);
    }
    return res;
  }

  std::pair<T, U> minimum_cost_maximum_flow(const int s, const int t,
                                            const T flow) {
    if (flow == 0) return {0, 0};
    T f = flow;
    U cost = 0;
    has_negative_edge ? bellman_ford(s) : dijkstra(s);
    while (dist[t] != uinf) {
      cost += calc(s, t, &f);
      if (f == 0) break;
      dijkstra(s);
    }
    return {flow - f, cost};
  }

 private:
  const T tinf;
  const int n;
  bool has_negative_edge;
  std::vector<int> prev_v, prev_e;
  std::vector<U> dist, potential;
  std::priority_queue<std::pair<U, int>, std::vector<std::pair<U, int>>,
                      std::greater<std::pair<U, int>>> que;

  void bellman_ford(const int s) {
    std::fill(dist.begin(), dist.end(), uinf);
    dist[s] = 0;
    bool is_updated = true;
    for (int step = 0; step < n && is_updated; ++step) {
      is_updated = false;
      for (int i = 0; i < n; ++i) {
        if (dist[i] == uinf) continue;
        for (int j = 0; std::cmp_less(j, graph[i].size()); ++j) {
          const Edge& e = graph[i][j];
          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {
            dist[e.dst] = dist[i] + e.cost;
            prev_v[e.dst] = i;
            prev_e[e.dst] = j;
            is_updated = true;
          }
        }
      }
    }
    assert(!is_updated);
    for (int i = 0; i < n; ++i) {
      if (dist[i] != uinf) potential[i] += dist[i];
    }
  }

  void dijkstra(const int s) {
    std::fill(dist.begin(), dist.end(), uinf);
    dist[s] = 0;
    que.emplace(0, s);
    while (!que.empty()) {
      const auto [d, ver] = que.top();
      que.pop();
      if (dist[ver] < d) continue;
      for (int i = 0; std::cmp_less(i, graph[ver].size()); ++i) {
        const Edge& e = graph[ver][i];
        const U nxt = dist[ver] + e.cost + potential[ver] - potential[e.dst];
        if (e.cap > 0 && dist[e.dst] > nxt) {
          dist[e.dst] = nxt;
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

  U calc(const int s, const int t, T* flow) {
    T f = *flow;
    for (int v = t; v != s; v = prev_v[v]) {
      f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);
    }
    *flow -= f;
    for (int v = t; v != s; v = prev_v[v]) {
      Edge& e = graph[prev_v[v]][prev_e[v]];
      e.cap -= f;
      graph[v][e.rev].cap += f;
    }
    return potential[t] * f;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_S_T_FLOW_HPP_
