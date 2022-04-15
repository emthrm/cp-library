---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: union-find
  - icon: ':question:'
    path: graph/edge.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\n#include \"../data_structure/union-find/union-find.hpp\"\
    \r\n#include \"./edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nUnionFind connencted_component_of_complement_graph(\r\
    \n    const std::vector<std::vector<Edge<CostType>>>& graph) {\r\n  const int\
    \ n = graph.size();\r\n  UnionFind union_find(n);\r\n  const auto check = [&graph,\
    \ n, &union_find](const int ver) -> void {\r\n    std::vector<bool> is_adjacent(n,\
    \ false);\r\n    for (const Edge<CostType>& e : graph[ver]) is_adjacent[e.dst]\
    \ = true;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (!is_adjacent[i]) union_find.unite(ver,\
    \ i);\r\n    }\r\n  };\r\n  int argmin_deg = 0;\r\n  for (int i = 1; i < n; ++i)\
    \ {\r\n    if (graph[i].size() < graph[argmin_deg].size()) argmin_deg = i;\r\n\
    \  }\r\n  check(argmin_deg);\r\n  for (const Edge<CostType>& e : graph[argmin_deg])\
    \ check(e.dst);\r\n  return union_find;\r\n}\r\n"
  dependsOn:
  - data_structure/union-find/union-find.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/connencted_component_of_complement_graph.hpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/connencted_component_of_complement_graph.test.cpp
documentation_of: graph/connencted_component_of_complement_graph.hpp
layout: document
title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
---


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`connencted_component_of_complement_graph(graph)`|無向グラフ $\mathrm{graph}$ の補グラフの連結成分分解|


## 参考

- https://betrue12.hateblo.jp/entry/2020/02/24/165627


## Verified

https://codeforces.com/contest/1242/submission/113385795
