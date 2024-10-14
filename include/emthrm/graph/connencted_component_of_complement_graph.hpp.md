---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/connencted_component_of_complement_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/connencted_component_of_complement_graph.hpp\"\
    \n\n\n\n#include <ranges>\n#include <vector>\n\n#line 1 \"include/emthrm/data_structure/union-find/union-find.hpp\"\
    \n\n\n\n#include <utility>\n#line 6 \"include/emthrm/data_structure/union-find/union-find.hpp\"\
    \n\nnamespace emthrm {\n\nstruct UnionFind {\n  explicit UnionFind(const int n)\
    \ : data(n, -1) {}\n\n  int root(const int ver) {\n    return data[ver] < 0 ?\
    \ ver : data[ver] = root(data[ver]);\n  }\n\n  bool unite(int u, int v) {\n  \
    \  u = root(u);\n    v = root(v);\n    if (u == v) return false;\n    if (data[u]\
    \ > data[v]) std::swap(u, v);\n    data[u] += data[v];\n    data[v] = u;\n   \
    \ return true;\n  }\n\n  bool is_same(const int u, const int v) { return root(u)\
    \ == root(v); }\n\n  int size(const int ver) { return -data[root(ver)]; }\n\n\
    \ private:\n  std::vector<int> data;\n};\n\n}  // namespace emthrm\n\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 9 \"include/emthrm/graph/connencted_component_of_complement_graph.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nUnionFind connencted_component_of_complement_graph(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const int n =\
    \ graph.size();\n  UnionFind union_find(n);\n  const auto check = [&graph, n,\
    \ &union_find](const int ver) -> void {\n    std::vector<bool> is_adjacent(n,\
    \ false);\n    for (const int e : graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      is_adjacent[e] = true;\n    }\n    for (int i = 0; i < n; ++i) {\n\
    \      if (!is_adjacent[i]) union_find.unite(ver, i);\n    }\n  };\n  int argmin_deg\
    \ = 0;\n  for (int i = 1; i < n; ++i) {\n    if (graph[i].size() < graph[argmin_deg].size())\
    \ argmin_deg = i;\n  }\n  check(argmin_deg);\n  for (const int e : graph[argmin_deg]\n\
    \                   | std::views::transform(&Edge<CostType>::dst)) {\n    check(e);\n\
    \  }\n  return union_find;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_CONNENCTED_COMPONENT_OF_COMPLEMENT_GRAPH_HPP_\n#define\
    \ EMTHRM_GRAPH_CONNENCTED_COMPONENT_OF_COMPLEMENT_GRAPH_HPP_\n\n#include <ranges>\n\
    #include <vector>\n\n#include \"emthrm/data_structure/union-find/union-find.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ CostType>\nUnionFind connencted_component_of_complement_graph(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  UnionFind union_find(n);\n  const\
    \ auto check = [&graph, n, &union_find](const int ver) -> void {\n    std::vector<bool>\
    \ is_adjacent(n, false);\n    for (const int e : graph[ver]\n                \
    \     | std::views::transform(&Edge<CostType>::dst)) {\n      is_adjacent[e] =\
    \ true;\n    }\n    for (int i = 0; i < n; ++i) {\n      if (!is_adjacent[i])\
    \ union_find.unite(ver, i);\n    }\n  };\n  int argmin_deg = 0;\n  for (int i\
    \ = 1; i < n; ++i) {\n    if (graph[i].size() < graph[argmin_deg].size()) argmin_deg\
    \ = i;\n  }\n  check(argmin_deg);\n  for (const int e : graph[argmin_deg]\n  \
    \                 | std::views::transform(&Edge<CostType>::dst)) {\n    check(e);\n\
    \  }\n  return union_find;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_CONNENCTED_COMPONENT_OF_COMPLEMENT_GRAPH_HPP_\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/union-find.hpp
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/connencted_component_of_complement_graph.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/connencted_component_of_complement_graph.test.cpp
documentation_of: include/emthrm/graph/connencted_component_of_complement_graph.hpp
layout: document
title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
---


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`UnionFind connencted_component_of_complement_graph(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ の補グラフの連結成分分解|


## 参考文献

- https://betrue12.hateblo.jp/entry/2020/02/24/165627


## Submissons

https://judge.yosupo.jp/submission/209943
