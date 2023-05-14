---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/traveling_salesman_problem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\
      \u984C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/traveling_salesman_problem.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <limits>\n#include <numeric>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/traveling_salesman_problem.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType>\nCostType traveling_salesman_problem(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph,\n    const CostType\
    \ inf = std::numeric_limits<CostType>::max()) {\n  const int n = graph.size();\n\
    \  if (n == 1) [[unlikely]] return 0;\n  std::vector<std::vector<CostType>> dp(1\
    \ << n, std::vector<CostType>(n, inf));\n  dp[1][0] = 0;\n  for (int i = 1; i\
    \ < (1 << n); ++i) {\n    for (int j = 0; j < n; ++j) {\n      if (dp[i][j] ==\
    \ inf) continue;\n      for (const Edge<CostType>& e : graph[j]) {\n        if\
    \ (i >> e.dst & 1) continue;\n        dp[i | (1 << e.dst)][e.dst] =\n        \
    \    std::min(dp[i | (1 << e.dst)][e.dst], dp[i][j] + e.cost);\n      }\n    }\n\
    \  }\n  CostType res = inf;\n  for (int j = 1; j < n; ++j) {\n    if (dp.back()[j]\
    \ == inf) continue;\n    for (const Edge<CostType>& e : graph[j]) {\n      if\
    \ (e.dst == 0) res = std::min(res, dp.back()[j] + e.cost);\n    }\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_TRAVELING_SALESMAN_PROBLEM_HPP_\n#define EMTHRM_GRAPH_TRAVELING_SALESMAN_PROBLEM_HPP_\n\
    \n#include <algorithm>\n#include <limits>\n#include <numeric>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ CostType>\nCostType traveling_salesman_problem(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n    const CostType inf = std::numeric_limits<CostType>::max()) {\n \
    \ const int n = graph.size();\n  if (n == 1) [[unlikely]] return 0;\n  std::vector<std::vector<CostType>>\
    \ dp(1 << n, std::vector<CostType>(n, inf));\n  dp[1][0] = 0;\n  for (int i =\
    \ 1; i < (1 << n); ++i) {\n    for (int j = 0; j < n; ++j) {\n      if (dp[i][j]\
    \ == inf) continue;\n      for (const Edge<CostType>& e : graph[j]) {\n      \
    \  if (i >> e.dst & 1) continue;\n        dp[i | (1 << e.dst)][e.dst] =\n    \
    \        std::min(dp[i | (1 << e.dst)][e.dst], dp[i][j] + e.cost);\n      }\n\
    \    }\n  }\n  CostType res = inf;\n  for (int j = 1; j < n; ++j) {\n    if (dp.back()[j]\
    \ == inf) continue;\n    for (const Edge<CostType>& e : graph[j]) {\n      if\
    \ (e.dst == 0) res = std::min(res, dp.back()[j] + e.cost);\n    }\n  }\n  return\
    \ res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_TRAVELING_SALESMAN_PROBLEM_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/traveling_salesman_problem.hpp
  requiredBy: []
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/traveling_salesman_problem.test.cpp
documentation_of: include/emthrm/graph/traveling_salesman_problem.hpp
layout: document
title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (traveling salesman\
  \ problem)"
---

重み付き有向グラフに対してコスト最小のハミルトン閉路を求める問題である。


## 時間計算量

$O(2^{\lvert V \rvert} {\lvert V \rvert}^2)$


## 仕様

### Held–Karp algorithm

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`CostType traveling_salesman_problem(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|グラフ $\mathrm{graph}$ の巡回セールスマン問題の解のコスト。ただし解が存在しないときは $\infty$ を返す。|


## 参考文献

Held–Karp algorithm
- Richard Bellman: Dynamic Programming Treatment of the Travelling Salesman Problem, *Journal of the ACM*, Vol. 9, No. 1, pp. 61–63 (1962). https://doi.org/10.1145/321105.321111
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.173-175，マイナビ出版（2012）


## TODO

- 最短のハミルトン路
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E8%B7%AF
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E9%96%89%E8%B7%AF%E5%95%8F%E9%A1%8C
  - ~~http://www.prefield.com/algorithm/graph/shortest_hamilton_path.html~~
  - https://github.com/primenumber/ProconLib/blob/master/Graph/ShortestHamiltonPath.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/hamilton_cycle_ore.cc


## Submissons

- [Held–Karp algorithm](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_2_A/review/5219970/emthrm/C++17)
