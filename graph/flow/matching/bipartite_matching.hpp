/**
 * @brief 二部グラフの最大マッチング
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <vector>

struct BipartiteMatching {
  std::vector<int> match;

  BipartiteMatching(int n) : n(n), graph(n), match(n, -1), used(n, -1), alive(n, true) {}

  void add_edge(int u, int v) {
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  int solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (alive[i] && match[i] == -1) {
        ++timestamp;
        if (dfs(i)) ++res;
      }
    }
    return res;
  }

  int push_back(int ver) {
    if (match[ver] != -1) match[match[ver]] = -1;
    match[ver] = -1;
    ++timestamp;
    dfs(ver);
    return match[ver];
  }

  void fix(int ver) {
    alive[ver] = false;
    if (match[ver] != -1) alive[match[ver]] = false;
  }

  int enable(int ver) {
    if (alive[ver]) return 0;
    alive[ver] = true;
    ++timestamp;
    return dfs(ver) ? 1 : 0;
  }

  int disable(int ver) {
    if (!alive[ver]) return 0;
    alive[ver] = false;
    if (match[ver] == -1) return 0;
    match[match[ver]] = -1;
    ++timestamp;
    int tmp = match[ver];
    match[ver] = -1;
    return dfs(tmp) ? 0 : -1;
  }

private:
  int n, timestamp = -1;
  std::vector<std::vector<int>> graph;
  std::vector<int> used;
  std::vector<bool> alive;

  bool dfs(int ver) {
    used[ver] = timestamp;
    for (int e : graph[ver]) {
      if (!alive[e]) continue;
      int tmp = match[e];
      if (tmp == -1 || (used[tmp] < timestamp && dfs(tmp))) {
        match[ver] = e;
        match[e] = ver;
        return true;
      }
    }
    return false;
  }
};
