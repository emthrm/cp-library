#pragma once
#include <algorithm>
#include <functional>
// #include <tuple>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> detect_bridge(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<std::pair<int, int>> res;
  std::vector<int> depth(n, -1), imos(n, 0);
  std::function<void(int, int)> dfs = [&graph, &res, &depth, &imos, &dfs](int par, int ver) -> void {
    bool multiedge = false;
    for (int e : graph[ver]) {
      if (depth[e] == -1) {
        depth[e] = depth[ver] + 1;
        dfs(ver, e);
        if (imos[e] == 0) res.emplace_back(std::minmax(ver, e));
        imos[ver] += imos[e];
      } else if (!multiedge && e == par) {
        multiedge = true;
      } else if (depth[e] < depth[ver]) {
        ++imos[ver];
        --imos[e];
      }
    }
  };
  for (int i = 0; i < n; ++i) {
    if (depth[i] == -1) {
      depth[i] = 0;
      dfs(-1, i);
    }
  }
  // std::sort(res.begin(), res.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
  //   int as, ad, bs, bd;
  //   std::tie(as, ad) = a;
  //   std::tie(bs, bd) = b;
  //   return as != bs ? as < bs : ad < bd;
  // });
  return res;
}
