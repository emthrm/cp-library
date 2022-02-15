#pragma once
#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
struct WarshallFloyd {
  std::vector<std::vector<T>> graph, dist;

  WarshallFloyd(const std::vector<std::vector<T>>& graph, const T inf)
      : graph(graph), dist(graph), inf(inf), n(graph.size()),
        internal(n, std::vector<int>(n, -1)) {
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][k] + dist[k][j] < dist[i][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
            internal[i][j] = k;
          }
        }
      }
    }
  }

  void add(const int src, const int dst, const T cost) {
    srcs.emplace_back(src);
    dsts.emplace_back(dst);
    costs.emplace_back(cost);
  }

  void calc() {
    const int m = srcs.size();
    for (int i = 0; i < m; ++i) {
      graph[srcs[i]][dsts[i]] = std::min(graph[srcs[i]][dsts[i]], costs[i]);
      if (costs[i] <= dist[srcs[i]][dsts[i]]) {
        dist[srcs[i]][dsts[i]] = costs[i];
        internal[srcs[i]][dsts[i]] = -1;
      }
    }
    std::vector<int> vers(m * 2);
    std::copy(srcs.begin(), srcs.end(), vers.begin());
    std::copy(dsts.begin(), dsts.end(), std::next(vers.begin(), m));
    std::sort(vers.begin(), vers.end());
    vers.erase(std::unique(vers.begin(), vers.end()), vers.end());
    for (const int ver : vers) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (dist[i][j] > dist[i][ver] + dist[ver][j]) {
            dist[i][j] = dist[i][ver] + dist[ver][j];
            internal[i][j] = ver;
          }
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

  std::vector<int> build_path(const int s, const int t) const {
    std::vector<int> res;
    if (dist[s][t] != inf) {
      build_path(s, t, &res);
      res.emplace_back(t);
    }
    return res;
  }

private:
  const T inf;
  const int n;
  std::vector<int> srcs, dsts;
  std::vector<T> costs;
  std::vector<std::vector<int>> internal;

  void build_path(const int s, const int t, std::vector<int>* path) const {
    const int k = internal[s][t];
    if (k == -1) {
      (*path).emplace_back(s);
    } else {
      build_path(s, k, path);
      build_path(k, t, path);
    }
  }
};
