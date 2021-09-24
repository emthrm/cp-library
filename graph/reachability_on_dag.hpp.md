---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological sort)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/reachability_on_dag.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\
      \u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <numeric>\r\
    \n#include <vector>\r\n#include \"edge.hpp\"\r\n#include \"topological_sort.hpp\"\
    \r\n\r\ntemplate <typename CostType>\r\nstd::vector<bool> reachability_on_dag(\r\
    \n  const std::vector<std::vector<Edge<CostType>>> &graph,\r\n  const std::vector<int>\
    \ &src,\r\n  const std::vector<int> &dst\r\n) {\r\n  constexpr int digits = std::numeric_limits<unsigned\
    \ long long>::digits;\r\n  const int n = graph.size(), q = src.size();\r\n  assert(dst.size()\
    \ == q);\r\n  std::vector<int> order = topological_sort(graph);\r\n  std::vector<bool>\
    \ can_reach(q, false);\r\n  std::vector<unsigned long long> dp(n, 0);\r\n  for\
    \ (int i = 0; i < q;) {\r\n    const int j = std::min(i + digits, q);\r\n    std::fill(dp.begin(),\
    \ dp.end(), 0);\r\n    for (int k = i; k < j; ++k) {\r\n      dp[src[k]] |= 1ull\
    \ << (k - i);\r\n    }\r\n    for (const int node : order) {\r\n      for (const\
    \ Edge<CostType> &e : graph[node]) {\r\n        dp[e.dst] |= dp[node];\r\n   \
    \   }\r\n    }\r\n    for (int k = i; k < j; ++k) {\r\n      can_reach[k] = dp[dst[k]]\
    \ >> (k - i) & 1;\r\n    }\r\n    i = j;\r\n  }\r\n  return can_reach;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/topological_sort.hpp
  isVerificationFile: false
  path: graph/reachability_on_dag.hpp
  requiredBy: []
  timestamp: '2021-08-19 19:52:18+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/reachability_on_dag.test.cpp
documentation_of: graph/reachability_on_dag.hpp
layout: document
title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\u53EF\
  \u80FD\u6027\u5224\u5B9A"
---


## 時間計算量

ワードサイズを $W$ とおくと $O\left(\frac{Q(\lvert V \rvert + \lvert E \rvert)}{W} \right)$．


## 使用法

||説明|
|:--:|:--:|
|`reachability_on_dag(graph, src, dst)`|有向非巡回グラフ $\mathrm{graph}$ 上で頂点 $\mathrm{src}_i$ から頂点 $\mathrm{dst}_i$ に到達できるか．|


## 参考

- https://ei1333.github.io/library/graph/others/offline-dag-reachability.hpp


## Verified

https://atcoder.jp/contests/typical90/submissions/25153847
