---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <queue>\r\n#include <vector>\r\n#include \"edge.hpp\"\
    \r\n\r\ntemplate <typename CostType>\r\nstd::vector<int> topological_sort(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph) {\r\n  int n = graph.size();\r\
    \n  std::vector<int> deg(n, 0);\r\n  for (int i = 0; i < n; ++i) {\r\n    for\
    \ (const Edge<CostType> &e : graph[i]) ++deg[e.dst];\r\n  }\r\n  std::queue<int>\
    \ que;\r\n  for (int i = 0; i < n; ++i) {\r\n    if (deg[i] == 0) que.emplace(i);\r\
    \n  }\r\n  std::vector<int> res;\r\n  while (!que.empty()) {\r\n    int ver =\
    \ que.front(); que.pop();\r\n    res.emplace_back(ver);\r\n    for (const Edge<CostType>\
    \ &e : graph[ver]) {\r\n      if (--deg[e.dst] == 0) que.emplace(e.dst);\r\n \
    \   }\r\n  }\r\n  return res.size() == n ? res : std::vector<int>();\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/topological_sort.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
---

有向非巡回グラフ (DAG) のトポロジカル順序を求めるアルゴリズムである．


### トポロジカル順序

$i$ 番目の頂点 $V_i$ について $V_i$ から $V_j$ に向かう辺があるとき
$i < j$ が成り立つ頂点の番号の付け方である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`topological_sort(graph)`|グラフ $\mathrm{graph}$ のトポロジカル順序|存在しない場合は空配列となる．|


## 参考

- https://github.com/spaghetti-source/algorithm/blob/master/graph/topological_sort.cc


## ToDo

- DAG の到達可能性
  - https://github.com/ei1333/library/blob/master/graph/offline-dag-reachability.cpp


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_4_B/review/4082498/emthrm/C++14
