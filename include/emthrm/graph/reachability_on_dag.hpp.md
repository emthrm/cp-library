---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/reachability_on_dag.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\
      \u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/reachability_on_dag.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <limits>\n#include\
    \ <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n\
    /**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/topological_sort.hpp\"\
    \n\n\n\n#include <queue>\n#include <ranges>\n#line 8 \"include/emthrm/graph/topological_sort.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
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
    \ res : std::vector<int>{};\n}\n\n}  // namespace emthrm\n\n\n#line 13 \"include/emthrm/graph/reachability_on_dag.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<bool> reachability_on_dag(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph,\n    const std::vector<int>&\
    \ ss, const std::vector<int>& ts) {\n  const int n = graph.size(), q = ss.size();\n\
    \  assert(std::cmp_equal(ts.size(), q));\n  const std::vector<int> order = topological_sort(graph);\n\
    \  std::vector<bool> can_reach(q, false);\n  std::vector<std::uint64_t> dp(n,\
    \ 0);\n  for (int i = 0; i < q;) {\n    const int j = std::min(i + std::numeric_limits<std::uint64_t>::digits,\
    \ q);\n    std::fill(dp.begin(), dp.end(), 0);\n    for (int k = i; k < j; ++k)\
    \ {\n      dp[ss[k]] |= UINT64_C(1) << (k - i);\n    }\n    for (const int node\
    \ : order) {\n      for (const int e : graph[node]\n                       | std::views::transform(&Edge<CostType>::dst))\
    \ {\n        dp[e] |= dp[node];\n      }\n    }\n    for (int k = i; k < j; ++k)\
    \ {\n      can_reach[k] = dp[ts[k]] >> (k - i) & 1;\n    }\n    i = j;\n  }\n\
    \  return can_reach;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_REACHABILITY_ON_DAG_HPP_\n#define EMTHRM_GRAPH_REACHABILITY_ON_DAG_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <limits>\n\
    #include <utility>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\
    #include \"emthrm/graph/topological_sort.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename CostType>\nstd::vector<bool> reachability_on_dag(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n    const std::vector<int>& ss, const std::vector<int>& ts) {\n  const\
    \ int n = graph.size(), q = ss.size();\n  assert(std::cmp_equal(ts.size(), q));\n\
    \  const std::vector<int> order = topological_sort(graph);\n  std::vector<bool>\
    \ can_reach(q, false);\n  std::vector<std::uint64_t> dp(n, 0);\n  for (int i =\
    \ 0; i < q;) {\n    const int j = std::min(i + std::numeric_limits<std::uint64_t>::digits,\
    \ q);\n    std::fill(dp.begin(), dp.end(), 0);\n    for (int k = i; k < j; ++k)\
    \ {\n      dp[ss[k]] |= UINT64_C(1) << (k - i);\n    }\n    for (const int node\
    \ : order) {\n      for (const int e : graph[node]\n                       | std::views::transform(&Edge<CostType>::dst))\
    \ {\n        dp[e] |= dp[node];\n      }\n    }\n    for (int k = i; k < j; ++k)\
    \ {\n      can_reach[k] = dp[ts[k]] >> (k - i) & 1;\n    }\n    i = j;\n  }\n\
    \  return can_reach;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_REACHABILITY_ON_DAG_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/topological_sort.hpp
  isVerificationFile: false
  path: include/emthrm/graph/reachability_on_dag.hpp
  requiredBy: []
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/reachability_on_dag.test.cpp
documentation_of: include/emthrm/graph/reachability_on_dag.hpp
layout: document
title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\u53EF\
  \u80FD\u6027\u5224\u5B9A"
---


## 時間計算量

ワードサイズを $W$ とおくと $O\left(\frac{Q(\lvert V \rvert + \lvert E \rvert)}{W} \right)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<bool> reachability_on_dag(const std::vector<std::vector<Edge<CostType>>>& graph, const std::vector<int>& ss, const std::vector<int>& ts);`|有向非巡回グラフ $\mathrm{graph}$ 上で頂点 $\mathrm{ss}_i$ から頂点 $\mathrm{ts}_i$ に到達できるか。|


## 参考文献

- https://ei1333.github.io/library/graph/others/offline-dag-reachability.hpp


## Submissons

https://atcoder.jp/contests/typical90/submissions/25153847