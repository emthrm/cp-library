/**
 * @brief Hopcroft–Karp algorithm
 * @docs docs/graph/flow/matching/matching.md
 */

#pragma once
#include <algorithm>
#include <queue>
#include <vector>

struct HopcroftKarp {
  std::vector<int> match;

  explicit HopcroftKarp(const int left, const int right)
      : match(left + right, -1), left(left), t(0), level(left),
        is_used(left, -1), graph(left) {}

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
        for (const int dst : graph[ver]) {
          if (match[dst] != -1 && level[match[dst]] == -1) {
            level[match[dst]] = level[ver] + 1;
            que.emplace(match[dst]);
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
      if (tmp == 0) break;
      res += tmp;
    }
    return res;
  }

 private:
  const int left;
  int t;
  std::vector<int> level, is_used;
  std::vector<std::vector<int>> graph;

  bool dfs(const int ver) {
    is_used[ver] = t;
    for (const int dst : graph[ver]) {
      const int m = match[dst];
      if (m == -1 || (is_used[m] < t && level[m] == level[ver] + 1 && dfs(m))) {
        is_used[ver] = t;
        match[ver] = dst;
        match[dst] = ver;
        return true;
      }
    }
    return false;
  }
};
