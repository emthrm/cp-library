---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/girth.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5185\u5468"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/girth.md
    document_title: "\u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/girth_in_directed_graph.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248\r\n *\
    \ @docs docs/graph/girth.md\r\n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\
    \n#include <limits>\r\n#include <queue>\r\n#include <tuple>\r\n#include <utility>\r\
    \n#include <vector>\r\n#include \"edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\
    \nCostType girth_in_directed_graph(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph,\r\n                                 const CostType inf = std::numeric_limits<CostType>::max())\
    \ {\r\n  int n = graph.size();\r\n  CostType res = inf;\r\n  std::vector<CostType>\
    \ dist(n);\r\n  using Pci = std::pair<CostType, int>;\r\n  std::priority_queue<Pci,\
    \ std::vector<Pci>, std::greater<Pci>> que;\r\n  for (int root = 0; root < n;\
    \ ++root) {\r\n    std::fill(dist.begin(), dist.end(), inf);\r\n    dist[root]\
    \ = 0;\r\n    que.emplace(0, root);\r\n    while (!que.empty()) {\r\n      CostType\
    \ cost; int ver; std::tie(cost, ver) = que.top(); que.pop();\r\n      if (dist[ver]\
    \ < cost) continue;\r\n      for (const Edge<CostType> &e : graph[ver]) {\r\n\
    \        CostType cost = dist[ver] + e.cost;\r\n        if (cost < dist[e.dst])\
    \ {\r\n          dist[e.dst] = cost;\r\n          que.emplace(cost, e.dst);\r\n\
    \        } else if (e.dst == root) {\r\n          if (cost < res) res = cost;\r\
    \n        }\r\n      }\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/girth_in_directed_graph.hpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/girth.test.cpp
documentation_of: graph/girth_in_directed_graph.hpp
layout: document
redirect_from:
- /library/graph/girth_in_directed_graph.hpp
- /library/graph/girth_in_directed_graph.hpp.html
title: "\u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248"
---
# 内周 (girth)

グラフにおける最小閉路長である．


## 時間計算量

$O(\lvert V \rvert (\lvert V \rvert + \lvert E \rvert) \log{\lvert V \rvert})$


## 使用法

- 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`girth_in_directed_graph(graph, ∞)`|有向グラフ $\mathrm{graph}$ の内周|辺の重みは自然数でなければならない．<br>存在しない場合は $\infty$ となる．|

- 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`girth_in_undirected_graph(n, edges, ∞)`|頂点数 $n$，辺集合 $\mathrm{edges}$ である無向グラフの内周|辺の重みは自然数でなければならない．<br>存在しない場合は $\infty$ となる．|


## 参考

- https://yukicoder.me/problems/no/1320/editorial
- https://algo-logic.info/minimum-weight-cycle/


## Verified

https://yukicoder.me/submissions/595363
