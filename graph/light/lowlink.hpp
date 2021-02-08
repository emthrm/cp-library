#pragma once
#include <algorithm>
#include <utility>
#include <vector>

struct Lowlink {
  std::vector<std::vector<int>> graph;
  std::vector<int> ap;
  std::vector<std::pair<int, int>> bridge;

  Lowlink(const std::vector<std::vector<int>> &graph) : graph(graph) {
    int n = graph.size();
    order.assign(n, -1);
    lowlink.resize(n);
    int tm = 0;
    for (int i = 0; i < n; ++i) {
      if (order[i] == -1) dfs(-1, i, tm);
    }
    // std::sort(ap.begin(), ap.end());
    // std::sort(bridge.begin(), bridge.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
    //   int as, ad, bs, bd;
    //   std::tie(as, ad) = a;
    //   std::tie(bs, bd) = b;
    //   return as != bs ? as < bs : ad < bd;
    // });
  }

  std::vector<int> order, lowlink;
private:
  void dfs(int par, int ver, int &tm) {
    order[ver] = lowlink[ver] = tm++;
    int cnt = 0;
    bool is_ap = false;
    for (int e : graph[ver]) {
      if (order[e] == -1) {
        ++cnt;
        dfs(ver, e, tm);
        if (lowlink[e] < lowlink[ver]) lowlink[ver] = lowlink[e];
        if (order[ver] <= lowlink[e]) {
          is_ap = true;
          if (order[ver] < lowlink[e]) bridge.emplace_back(std::minmax(ver, e));
        }
      } else if (e != par) {
        if (order[e] < lowlink[ver]) lowlink[ver] = order[e];
      }
    }
    if (par == -1) {
      if (cnt >= 2) ap.emplace_back(ver);
    } else {
      if (is_ap) ap.emplace_back(ver);
    }
  }
};
