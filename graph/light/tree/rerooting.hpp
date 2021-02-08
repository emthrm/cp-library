#pragma once
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>

int rerooting(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> dist(n, 0);
  std::vector<std::vector<std::pair<int, int>>> children(n);
  std::function<void(int, int)> dfs1 = [&graph, &dist, &children, &dfs1](int par, int ver) -> void {
    for (int e : graph[ver]) {
      if (e != par) {
        dfs1(ver, e);
        if (dist[e] + 1 > dist[ver]) dist[ver] = dist[e] + 1;
        children[ver].emplace_back(dist[e] + 1, e);
      }
    }
  };
  dfs1(-1, 0);
  std::vector<int> dp(n);
  std::function<void(int, int, int)> dfs2 = [&graph, &children, &dp, &dfs2](int par, int ver, int par_dp) -> void {
    if (par != -1) children[ver].emplace_back(par_dp, par);
    std::sort(children[ver].begin(), children[ver].end(), std::greater<std::pair<int, int>>());
    if (children[ver].size() == 1) {
      dp[ver] = children[ver].front().first;
      if (par == -1) dfs2(ver, graph[ver].front(), 1);
    } else {
      dp[ver] = children[ver][0].first + children[ver][1].first;
      for (int e : graph[ver]) {
        if (e != par) dfs2(ver, e, children[ver][children[ver][0].second == e ? 1 : 0].first + 1);
      }
    }
  };
  if (n == 1) {
    dp[0] = 0;
  } else {
    dfs2(-1, 0, 0);
  }
  return *std::max_element(dp.begin(), dp.end());
}
