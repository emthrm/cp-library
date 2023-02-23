---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/graph/girth_in_directed_graph.hpp: line 16: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248\n * @docs\
    \ docs/graph/girth.md\n */\n\n#ifndef EMTHRM_GRAPH_GIRTH_IN_DIRECTED_GRAPH_HPP_\n\
    #define EMTHRM_GRAPH_GIRTH_IN_DIRECTED_GRAPH_HPP_\n\n#include <algorithm>\n#include\
    \ <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename CostType>\nCostType girth_in_directed_graph(\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n    const CostType inf = std::numeric_limits<CostType>::max()) {\n \
    \ const int n = graph.size();\n  CostType res = inf;\n  std::vector<CostType>\
    \ dist(n);\n  std::priority_queue<std::pair<CostType, int>,\n                \
    \      std::vector<std::pair<CostType, int>>,\n                      std::greater<std::pair<CostType,\
    \ int>>> que;\n  for (int root = 0; root < n; ++root) {\n    std::fill(dist.begin(),\
    \ dist.end(), inf);\n    dist[root] = 0;\n    que.emplace(dist[root], root);\n\
    \    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n      que.pop();\n\
    \      if (d > dist[ver]) continue;\n      for (const Edge<CostType>& e : graph[ver])\
    \ {\n        const CostType nxt = dist[ver] + e.cost;\n        if (nxt < dist[e.dst])\
    \ {\n          dist[e.dst] = nxt;\n          que.emplace(nxt, e.dst);\n      \
    \  } else if (e.dst == root) {\n          res = std::min(res, nxt);\n        }\n\
    \      }\n    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_GRAPH_GIRTH_IN_DIRECTED_GRAPH_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/girth_in_directed_graph.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/girth.test.cpp
documentation_of: include/emthrm/graph/girth_in_directed_graph.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/girth_in_directed_graph.hpp
- /library/include/emthrm/graph/girth_in_directed_graph.hpp.html
title: "\u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248"
---
# 内周 (girth)

グラフに対する最小閉路長である。


## 時間計算量

$O(\lvert V \rvert (\lvert V \rvert + \lvert E \rvert) \log{\lvert V \rvert})$


## 仕様

### 有向グラフ版

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename CostType>`<br>`CostType girth_in_directed_graph(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|有向グラフ $\mathrm{graph}$ の内周。ただし存在しないときは $\infty$ を返す。|辺の重みは自然数である。|


### 無向グラフ版

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename CostType>`<br>`CostType girth_in_undirected_graph(const int n, const std::vector<Edge<CostType>>& edges, const CostType inf = std::numeric_limits<CostType>::max());`|頂点数 $n$、辺集合 $\mathrm{edges}$ である無向グラフの内周。ただし存在しないときは $\infty$ を返す。|辺の重みは自然数である。|


## 参考文献

- https://yukicoder.me/problems/no/1320/editorial
- https://algo-logic.info/minimum-weight-cycle/


## TODO

- minimum mean-weight cycle
  - https://37zigen.com/%E6%9C%80%E5%B0%8F%E5%B9%B3%E5%9D%87%E9%95%B7%E9%96%89%E8%B7%AF%E5%95%8F%E9%A1%8C/
  - https://kopricky.github.io/code/Graph/directed_minimum_mean_weight_cycle_memo.html


## Submissons

https://yukicoder.me/submissions/595363
