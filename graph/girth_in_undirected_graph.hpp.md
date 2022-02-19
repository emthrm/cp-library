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
    document_title: "\u5185\u5468 \u7121\u5411\u30B0\u30E9\u30D5\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/girth_in_undirected_graph.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u5185\u5468 \u7121\u5411\u30B0\u30E9\u30D5\u7248\r\n *\
    \ @docs docs/graph/girth.md\r\n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\
    \n#include <functional>\r\n#include <limits>\r\n#include <queue>\r\n#include <tuple>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\n#include \"edge.hpp\"\r\n\r\n\
    template <typename CostType>\r\nCostType girth_in_undirected_graph(\r\n    const\
    \ int n, const std::vector<Edge<CostType>>& edges,\r\n    const CostType inf =\
    \ std::numeric_limits<CostType>::max()) {\r\n  const int m = edges.size();\r\n\
    \  std::vector<std::vector<int>> graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\
    \n    graph[edges[i].src].emplace_back(i);\r\n    graph[edges[i].dst].emplace_back(i);\r\
    \n  }\r\n  std::vector<bool> is_used(m, false);\r\n  std::vector<int> label(n),\
    \ prev(n);\r\n  std::vector<CostType> dist(n);\r\n  std::priority_queue<std::pair<CostType,\
    \ int>,\r\n                      std::vector<std::pair<CostType, int>>,\r\n  \
    \                    std::greater<std::pair<CostType, int>>> que;\r\n  CostType\
    \ res = inf;\r\n  for (int root = 0; root < n; ++root) {\r\n    std::fill(is_used.begin(),\
    \ is_used.end(), false);\r\n    std::fill(label.begin(), label.end(), -2);\r\n\
    \    label[root] = -1;\r\n    std::fill(prev.begin(), prev.end(), -1);\r\n   \
    \ std::fill(dist.begin(), dist.end(), inf);\r\n    dist[root] = 0;\r\n    que.emplace(0,\
    \ root);\r\n    while (!que.empty()) {\r\n      CostType d;\r\n      int ver;\r\
    \n      std::tie(d, ver) = que.top();\r\n      que.pop();\r\n      if (d > dist[ver])\
    \ continue;\r\n      for (const int id : graph[ver]) {\r\n        const int dst\
    \ = (edges[id].src == ver ? edges[id].dst : edges[id].src);\r\n        const CostType\
    \ nxt = dist[ver] + edges[id].cost;\r\n        if (nxt < dist[dst]) {\r\n    \
    \      dist[dst] = nxt;\r\n          label[dst] = (label[ver] == -1 ? dst : label[ver]);\r\
    \n          if (prev[dst] != -1) is_used[dst] = true;\r\n          is_used[id]\
    \ = true;\r\n          que.emplace(nxt, dst);\r\n        }\r\n      }\r\n    }\r\
    \n    for (int i = 0; i < m; ++i) {\r\n      const int src = edges[i].src, dst\
    \ = edges[i].dst;\r\n      if (!is_used[i] && label[src] != -2 && label[dst] !=\
    \ -2) {\r\n        if (label[src] != label[dst]) {\r\n          res = std::min(res,\
    \ dist[src] + dist[dst] + edges[i].cost);\r\n        } else if (label[src] ==\
    \ -1) {\r\n          res = std::min(res, edges[i].cost);\r\n        }\r\n    \
    \  }\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/girth_in_undirected_graph.hpp
  requiredBy: []
  timestamp: '2022-02-15 21:43:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/girth.test.cpp
documentation_of: graph/girth_in_undirected_graph.hpp
layout: document
redirect_from:
- /library/graph/girth_in_undirected_graph.hpp
- /library/graph/girth_in_undirected_graph.hpp.html
title: "\u5185\u5468 \u7121\u5411\u30B0\u30E9\u30D5\u7248"
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
