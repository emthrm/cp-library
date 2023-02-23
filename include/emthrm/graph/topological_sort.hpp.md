---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':x:'
    path: include/emthrm/graph/reachability_on_dag.hpp
    title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\
      \u53EF\u80FD\u6027\u5224\u5B9A"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/reachability_on_dag.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\
      \u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
  - icon: ':x:'
    path: test/graph/topological_sort.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
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
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
