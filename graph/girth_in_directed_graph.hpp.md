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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/girth_in_directed_graph.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248\n * @docs\
    \ docs/graph/girth.md\n */\n\n#pragma once\n#include <algorithm>\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"./edge.hpp\"\n\ntemplate <typename CostType>\nCostType\
    \ girth_in_directed_graph(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n    const CostType inf = std::numeric_limits<CostType>::max()) {\n \
    \ const int n = graph.size();\n  CostType res = inf;\n  std::vector<CostType>\
    \ dist(n);\n  std::priority_queue<std::pair<CostType, int>,\n                \
    \      std::vector<std::pair<CostType, int>>,\n                      std::greater<std::pair<CostType,\
    \ int>>> que;\n  for (int root = 0; root < n; ++root) {\n    std::fill(dist.begin(),\
    \ dist.end(), inf);\n    dist[root] = 0;\n    que.emplace(dist[root], root);\n\
    \    while (!que.empty()) {\n      CostType d;\n      int ver;\n      std::tie(d,\
    \ ver) = que.top();\n      que.pop();\n      if (d > dist[ver]) continue;\n  \
    \    for (const Edge<CostType>& e : graph[ver]) {\n        const CostType nxt\
    \ = dist[ver] + e.cost;\n        if (nxt < dist[e.dst]) {\n          dist[e.dst]\
    \ = nxt;\n          que.emplace(nxt, e.dst);\n        } else if (e.dst == root)\
    \ {\n          res = std::min(res, nxt);\n        }\n      }\n    }\n  }\n  return\
    \ res;\n}\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/girth_in_directed_graph.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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

グラフに対する最小閉路長である．


## 時間計算量

$O(\lvert V \rvert (\lvert V \rvert + \lvert E \rvert) \log{\lvert V \rvert})$


## 使用法

- 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`girth_in_directed_graph(graph, ∞)`|有向グラフ $\mathrm{graph}$ の内周|辺の重みは自然数でなければならない．<br>存在しないときは $\infty$ となる．|

- 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`girth_in_undirected_graph(n, edges, ∞)`|頂点数 $n$，辺集合 $\mathrm{edges}$ である無向グラフの内周|辺の重みは自然数でなければならない．<br>存在しないときは $\infty$ となる．|


## 参考

- https://yukicoder.me/problems/no/1320/editorial
- https://algo-logic.info/minimum-weight-cycle/


## ToDo

- minimum mean-weight cycle
  - https://37zigen.com/%E6%9C%80%E5%B0%8F%E5%B9%B3%E5%9D%87%E9%95%B7%E9%96%89%E8%B7%AF%E5%95%8F%E9%A1%8C/
  - https://kopricky.github.io/code/Graph/directed_minimum_mean_weight_cycle_memo.html


## Verified

https://yukicoder.me/submissions/595363
