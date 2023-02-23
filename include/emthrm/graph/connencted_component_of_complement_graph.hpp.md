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
  - icon: ':x:'
    path: test/graph/connencted_component_of_complement_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\
      \u5206\u89E3"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/union-find/union-find.hpp:\
    \ line -1: no such header\n"
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
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

https://codeforces.com/contest/1242/submission/113385795
