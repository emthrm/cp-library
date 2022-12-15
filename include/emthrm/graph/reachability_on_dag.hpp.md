---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: include/emthrm/graph/topological_sort.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GRAPH_REACHABILITY_ON_DAG_HPP_\n#define EMTHRM_GRAPH_REACHABILITY_ON_DAG_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <cstdint>\n#include <limits>\n\
    #include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/topological_sort.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<bool> reachability_on_dag(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph,\n    const std::vector<int>&\
    \ ss, const std::vector<int>& ts) {\n  const int n = graph.size(), q = ss.size();\n\
    \  assert(static_cast<int>(ts.size()) == q);\n  const std::vector<int> order =\
    \ topological_sort(graph);\n  std::vector<bool> can_reach(q, false);\n  std::vector<std::uint64_t>\
    \ dp(n, 0);\n  for (int i = 0; i < q;) {\n    const int j = std::min(i + std::numeric_limits<std::uint64_t>::digits,\
    \ q);\n    std::fill(dp.begin(), dp.end(), 0);\n    for (int k = i; k < j; ++k)\
    \ {\n      dp[ss[k]] |= UINT64_C(1) << (k - i);\n    }\n    for (const int node\
    \ : order) {\n      for (const Edge<CostType>& e : graph[node]) dp[e.dst] |= dp[node];\n\
    \    }\n    for (int k = i; k < j; ++k) {\n      can_reach[k] = dp[ts[k]] >> (k\
    \ - i) & 1;\n    }\n    i = j;\n  }\n  return can_reach;\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_REACHABILITY_ON_DAG_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/topological_sort.hpp
  isVerificationFile: false
  path: include/emthrm/graph/reachability_on_dag.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/reachability_on_dag.test.cpp
documentation_of: include/emthrm/graph/reachability_on_dag.hpp
layout: document
title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\u53EF\
  \u80FD\u6027\u5224\u5B9A"
---


## 時間計算量

ワードサイズを $W$ とおくと $O\left(\frac{Q(\lvert V \rvert + \lvert E \rvert)}{W} \right)$．


## 使用法

||説明|
|:--:|:--:|
|`reachability_on_dag(graph, ss, ts)`|有向非巡回グラフ $\mathrm{graph}$ 上で頂点 $\mathrm{ss}_i$ から頂点 $\mathrm{ts}_i$ に到達できるか．|


## 参考

- https://ei1333.github.io/library/graph/others/offline-dag-reachability.hpp


## Verified

https://atcoder.jp/contests/typical90/submissions/25153847
