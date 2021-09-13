/**
 * @brief Hopcroft-Karp algorithm
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <algorithm>
#include <queue>
#include <vector>

struct HopcroftKarp {
  std::vector<int> match;

  HopcroftKarp(const int left, const int right)
  : left(left), graph(left), match(left + right, -1), level(left), is_used(left, -1) {}

  void add_edge(const int u, const int v) {
    graph[u].emplace_back(left + v);
  }

  int solve() {
    int res = 0;
    while (true) {
      std::fill(level.begin(), level.end(), -1);
      std::queue<int> que;
      for (int i = 0; i < left; ++i) {
        if (match[i] == -1) {
          que.emplace(i);
          level[i] = 0;
        }
      }
      while (!que.empty()) {
        const int ver = que.front();
        que.pop();
        for (const int e : graph[ver]) {
          if (match[e] != -1 && level[match[e]] == -1) {
            level[match[e]] = level[ver] + 1;
            que.emplace(match[e]);
          }
        }
      }
      int tmp = 0;
      for (int i = 0; i < left; ++i) {
        if (match[i] == -1) {
          tmp += dfs(i);
          ++t;
        }
      }
      if (tmp == 0) return res;
      res += tmp;
    }
  }

private:
  const int left;
  int t = 0;
  std::vector<std::vector<int>> graph;
  std::vector<int> level, is_used;

  bool dfs(const int ver) {
    is_used[ver] = t;
    for (const int e : graph[ver]) {
      const int m = match[e];
      if (m == -1 || (is_used[m] < t && level[m] == level[ver] + 1 && dfs(m))) {
        is_used[ver] = t;
        match[ver] = e;
        match[e] = ver;
        return true;
      }
    }
    return false;
  }
};
