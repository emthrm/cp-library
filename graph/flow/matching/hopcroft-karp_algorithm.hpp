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

  HopcroftKarp(int left, int right) : left(left), graph(left), match(left + right, -1), level(left), used(left, -1) {}

  void add_edge(int u, int v) { graph[u].emplace_back(left + v); }

  int solve() {
    int res = 0;
    while (true) {
      bfs();
      int tmp = 0;
      for (int i = 0; i < left; ++i) {
        if (match[i] == -1) {
          if (dfs(i)) ++tmp;
          ++timestamp;
        }
      }
      if (tmp == 0) return res;
      res += tmp;
    }
  }

private:
  int left, timestamp = 0;
  std::vector<std::vector<int>> graph;
  std::vector<int> level, used;

  void bfs() {
    std::fill(level.begin(), level.end(), -1);
    std::queue<int> que;
    for (int i = 0; i < left; ++i) {
      if (match[i] == -1) {
        que.emplace(i);
        level[i] = 0;
      }
    }
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (int e : graph[ver]) {
        if (match[e] != -1 && level[match[e]] == -1) {
          level[match[e]] = level[ver] + 1;
          que.emplace(match[e]);
        }
      }
    }
  }

  bool dfs(int ver) {
    used[ver] = timestamp;
    for (int e : graph[ver]) {
      int tmp = match[e];
      if (tmp == -1 || (used[tmp] < timestamp && level[tmp] == level[ver] + 1 && dfs(tmp))) {
        used[ver] = timestamp;
        match[e] = ver;
        match[ver] = e;
        return true;
      }
    }
    return false;
  }
};
