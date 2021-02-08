#pragma once
#include <set>
#include <vector>

template <typename T>
struct WarshallFloyd {
  std::vector<std::vector<T>> graph, dist;

  WarshallFloyd(const std::vector<std::vector<T>> &graph, const T TINF) : graph(graph), dist(graph), TINF(TINF) {
    n = graph.size();
    internal.assign(n, std::vector<int>(n, -1));
    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      if (dist[i][j] > dist[i][k] + dist[k][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
        internal[i][j] = k;
      }
    }
  }

  void add(int src, int dst, T cost) {
    srcs.emplace_back(src);
    dsts.emplace_back(dst);
    costs.emplace_back(cost);
  }

  void calc() {
    std::set<int> vers;
    int sz = srcs.size();
    for (int i = 0; i < sz; ++i) {
      int s = srcs[i], t = dsts[i];
      T cost = costs[i];
      if (cost < graph[s][t]) graph[s][t] = cost;
      if (dist[s][t] >= cost) {
        dist[s][t] = cost;
        internal[s][t] = -1;
      }
      vers.emplace(s);
      vers.emplace(t);
    }
    for (int v : vers) {
      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        if (dist[i][j] > dist[i][v] + dist[v][j]) {
          dist[i][j] = dist[i][v] + dist[v][j];
          internal[i][j] = v;
        }
      }
    }
    srcs.clear();
    dsts.clear();
    costs.clear();
  }

  bool has_negative_cycle() const {
    for (int i = 0; i < n; ++i) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }

  std::vector<int> build_path(int s, int t) const {
    std::vector<int> res;
    if (dist[s][t] != TINF) {
      build_path(s, t, res);
      res.emplace_back(t);
    }
    return res;
  }

private:
  const T TINF;
  int n;
  std::vector<std::vector<int>> internal;
  std::vector<int> srcs, dsts;
  std::vector<T> costs;

  void build_path(int s, int t, std::vector<int> &path) const {
    int k = internal[s][t];
    if (k == -1) {
      path.emplace_back(s);
    } else {
      build_path(s, k, path);
      build_path(k, t, path);
    }
  }
};
