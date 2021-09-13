/**
 * @brief 二部グラフの最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <vector>

struct BipartiteMatching {
  std::vector<int> match;

  BipartiteMatching(const int n)
  : n(n), match(n, -1), graph(n), is_used(n, 0), is_alive(n, true) {}

  void add_edge(const int u, const int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  int solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (is_alive[i] && match[i] == -1) {
        ++t;
        res += dfs(i);
      }
    }
    return res;
  }

  void fix(const int ver) {
    is_alive[ver] = false;
    if (match[ver] != -1) {
      is_alive[match[ver]] = false;
    }
  }

  int enable(const int ver) {
    if (is_alive[ver]) return 0;
    is_alive[ver] = true;
    ++t;
    return dfs(ver) ? 1 : 0;
  }

  int disable(const int ver) {
    if (!is_alive[ver]) return 0;
    is_alive[ver] = false;
    if (match[ver] == -1) return 0;
    match[match[ver]] = -1;
    const int m = match[ver];
    match[ver] = -1;
    ++t;
    return dfs(m) ? 0 : -1;
  }

private:
  const int n;
  int t = 0;
  std::vector<std::vector<int>> graph;
  std::vector<int> is_used, is_alive;

  bool dfs(const int ver) {
    is_used[ver] = t;
    for (const int e : graph[ver]) {
      if (!is_alive[e]) continue;
      const int m = match[e];
      if (m == -1 || (is_used[m] < t && dfs(m))) {
        match[ver] = e;
        match[e] = ver;
        return true;
      }
    }
    return false;
  }
};
