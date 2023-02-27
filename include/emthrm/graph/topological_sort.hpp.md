---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':question:'
    path: include/emthrm/graph/reachability_on_dag.hpp
    title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\
      \u53EF\u80FD\u6027\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/reachability_on_dag.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\
      \u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
  - icon: ':warning:'
    path: test/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/topological_sort.hpp\"\n\n\n\n#include\
    \ <queue>\n#include <ranges>\n#include <utility>\n#include <vector>\n\n#line 1\
    \ \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/topological_sort.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nstd::vector<int> topological_sort(\n    const\
    \ std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n = graph.size();\n\
    \  std::vector<int> deg(n, 0);\n  for (const int e : graph\n                 \
    \  | std::views::join\n                   | std::views::transform(&Edge<CostType>::dst))\
    \ {\n    ++deg[e];\n  }\n  std::queue<int> que;\n  for (int i = 0; i < n; ++i)\
    \ {\n    if (deg[i] == 0) que.emplace(i);\n  }\n  std::vector<int> res;\n  res.reserve(n);\n\
    \  while (!que.empty()) {\n    const int ver = que.front();\n    que.pop();\n\
    \    res.emplace_back(ver);\n    for (const int e : graph[ver]\n             \
    \        | std::views::transform(&Edge<CostType>::dst)) {\n      if (--deg[e]\
    \ == 0) que.emplace(e);\n    }\n  }\n  return std::cmp_equal(res.size(), n) ?\
    \ res : std::vector<int>{};\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_TOPOLOGICAL_SORT_HPP_\n#define EMTHRM_GRAPH_TOPOLOGICAL_SORT_HPP_\n\
    \n#include <queue>\n#include <ranges>\n#include <utility>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ CostType>\nstd::vector<int> topological_sort(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  std::vector<int> deg(n, 0);\n  for\
    \ (const int e : graph\n                   | std::views::join\n              \
    \     | std::views::transform(&Edge<CostType>::dst)) {\n    ++deg[e];\n  }\n \
    \ std::queue<int> que;\n  for (int i = 0; i < n; ++i) {\n    if (deg[i] == 0)\
    \ que.emplace(i);\n  }\n  std::vector<int> res;\n  res.reserve(n);\n  while (!que.empty())\
    \ {\n    const int ver = que.front();\n    que.pop();\n    res.emplace_back(ver);\n\
    \    for (const int e : graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (--deg[e] == 0) que.emplace(e);\n    }\n  }\n  return std::cmp_equal(res.size(),\
    \ n) ? res : std::vector<int>{};\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_TOPOLOGICAL_SORT_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/topological_sort.hpp
  requiredBy:
  - include/emthrm/graph/reachability_on_dag.hpp
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/reachability_on_dag.test.cpp
  - test/graph/topological_sort.test.cpp
documentation_of: include/emthrm/graph/topological_sort.hpp
layout: document
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
---

有向非巡回グラフ (directed acyclic graph) のトポロジカル順序を求めるアルゴリズムである。


### トポロジカル順序

$i$ 番目の頂点 $V_i$ に対して辺 $(V_i, V_j)$ が存在するならば $i < j$ を満たすような頂点の番号の付け方である。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<int> topological_sort(const std::vector<std::vector<Edge<CostType>>>& graph);`|グラフ $\mathrm{graph}$ のトポロジカル順序。ただし存在しないときは空配列を返す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.89-90，マイナビ出版（2012）
- https://github.com/spaghetti-source/algorithm/blob/8b1daaa3e80e5d954aac2632ef2299b1b86c55ed/graph/topological_sort.cc


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_4_B/review/4082498/emthrm/C++14
