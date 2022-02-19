---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/2-edge-connected_components_by_lowlink.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
  - icon: ':warning:'
    path: graph/biconnected_component.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component)\
      \ \u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/lowlink.1.test.cpp
    title: "\u30B0\u30E9\u30D5/lowlink (\u6A4B)"
  - icon: ':heavy_check_mark:'
    path: test/graph/lowlink.2.test.cpp
    title: "\u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\n#include\
    \ \"edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct Lowlink {\r\n  std::vector<int>\
    \ order, lowlink, articulation_points;\r\n  std::vector<Edge<CostType>> bridges;\r\
    \n  const std::vector<std::vector<Edge<CostType>>> graph;\r\n\r\n  explicit Lowlink(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph)\r\n      : graph(graph) {\r\
    \n    const int n = graph.size();\r\n    order.assign(n, -1);\r\n    lowlink.resize(n);\r\
    \n    int t = 0;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (order[i] ==\
    \ -1) dfs(-1, i, &t);\r\n    }\r\n  }\r\n\r\n private:\r\n  void dfs(const int\
    \ par, const int ver, int* t) {\r\n    order[ver] = lowlink[ver] = (*t)++;\r\n\
    \    int num = 0;\r\n    bool is_articulation_point = false;\r\n    for (const\
    \ Edge<CostType>& e : graph[ver]) {\r\n      if (order[e.dst] == -1) {\r\n   \
    \     ++num;\r\n        dfs(ver, e.dst, t);\r\n        lowlink[ver] = std::min(lowlink[ver],\
    \ lowlink[e.dst]);\r\n        if (order[ver] <= lowlink[e.dst]) {\r\n        \
    \  is_articulation_point = true;\r\n          if (order[ver] < lowlink[e.dst])\
    \ {\r\n            bridges.emplace_back(std::min(ver, e.dst), std::max(ver, e.dst),\r\
    \n                                 e.cost);\r\n          }\r\n        }\r\n  \
    \    } else if (e.dst != par) {\r\n        lowlink[ver] = std::min(lowlink[ver],\
    \ order[e.dst]);\r\n      }\r\n    }\r\n    if ((par == -1 && num >= 2) || (par\
    \ != -1 && is_articulation_point)) {\r\n      articulation_points.emplace_back(ver);\r\
    \n    }\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/biconnected_component.hpp
  - graph/2-edge-connected_components_by_lowlink.hpp
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/lowlink.1.test.cpp
  - test/graph/2-edge-connected_components_by_lowlink.test.cpp
  - test/graph/lowlink.2.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
title: lowlink
---

深さ優先探索木 (depth-first search tree) で訪問時刻を $\mathrm{order}$ とおくと，後退辺 (back edge) を高々一度通ることで到達できる頂点の $\mathrm{order}$ の最小値である．


### 橋 (bridge)

無向グラフ $G = (V, E)$ に対して，グラフ $(V, E \setminus \lbrace e \rbrace)$ が非連結となる辺 $e$ である．


### 関節点 (articulation point)

無向グラフ $G = (V, E)$ に対して，グラフ $(V \setminus \lbrace v \rbrace, E)$ が非連結となる頂点 $v$ である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Lowlink<CostType>(graph)`|無向グラフ $\mathrm{graph}$ の lowlink を考える．||
|`order[i]`|頂点 $i$ の訪問時刻||
|`lowlink`|lowlink||
|`articulation_points`|関節点の集合||
|`bridges`|橋の集合|多重辺に対応していない．|
|`graph`|無向グラフ||


## 参考

- http://kagamiz.hatenablog.com/entry/2013/10/05/005213


## Verified

- [橋](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082818/emthrm/C++14)
- [関節点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_A/review/4082810/emthrm/C++14)
