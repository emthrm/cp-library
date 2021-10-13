---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/2-edge-connected_components_lowlink.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
  - icon: ':x:'
    path: graph/biconnected_component.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component)\
      \ \u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/2-edge-connected_components_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  - icon: ':x:'
    path: test/graph/biconnected_component.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n#include \"\
    edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct Lowlink {\r\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\r\n  std::vector<int> order, lowlink, ap;\r\n  std::vector<Edge<CostType>>\
    \ bridge;\r\n\r\n  Lowlink(const std::vector<std::vector<Edge<CostType>>> &graph)\
    \ : graph(graph) {\r\n    int n = graph.size();\r\n    order.assign(n, -1);\r\n\
    \    lowlink.resize(n);\r\n    int tm = 0;\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n      if (order[i] == -1) dfs(-1, i, tm);\r\n    }\r\n    // std::sort(ap.begin(),\
    \ ap.end());\r\n    // std::sort(bridge.begin(), bridge.end(), [](const Edge<CostType>\
    \ &a, const Edge<CostType> &b) -> bool {\r\n    //   return a.src != b.src ? a.src\
    \ < b.src : a.dst != b.dst ? a.dst < b.dst : a.cost < b.cost;\r\n    // });\r\n\
    \  }\r\n\r\nprivate:\r\n  void dfs(int par, int ver, int &tm) {\r\n    order[ver]\
    \ = lowlink[ver] = tm++;\r\n    int cnt = 0;\r\n    bool is_ap = false;\r\n  \
    \  for (const Edge<CostType> &e : graph[ver]) {\r\n      if (order[e.dst] == -1)\
    \ {\r\n        ++cnt;\r\n        dfs(ver, e.dst, tm);\r\n        if (lowlink[e.dst]\
    \ < lowlink[ver]) lowlink[ver] = lowlink[e.dst];\r\n        if (order[ver] <=\
    \ lowlink[e.dst]) {\r\n          is_ap = true;\r\n          if (order[ver] < lowlink[e.dst])\
    \ bridge.emplace_back(std::min(ver, e.dst), std::max(ver, e.dst), e.cost);\r\n\
    \        }\r\n      } else if (e.dst != par) {\r\n        if (order[e.dst] < lowlink[ver])\
    \ lowlink[ver] = order[e.dst];\r\n      }\r\n    }\r\n    if (par == -1) {\r\n\
    \      if (cnt >= 2) ap.emplace_back(ver);\r\n    } else {\r\n      if (is_ap)\
    \ ap.emplace_back(ver);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy:
  - graph/biconnected_component.hpp
  - graph/2-edge-connected_components_lowlink.hpp
  timestamp: '2021-04-18 15:42:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/lowlink.2.test.cpp
  - test/graph/2-edge-connected_components_lowlink.test.cpp
  - test/graph/lowlink.1.test.cpp
  - test/graph/biconnected_component.test.cpp
documentation_of: graph/lowlink.hpp
layout: document
title: lowlink
---

深さ優先探索木 (depth-first search tree) において訪問時刻を $\mathrm{order}$ とおいたとき，後退辺 (back edge) を高々一度通ることで到達可能な頂点の $\mathrm{order}$ の最小値である．


### 橋 (bridge)

無向グラフ $G = (V, E)$ において，グラフ $(V, E - \lbrace e \rbrace)$ が非連結となる辺 $e$ である．


### 関節点 (articulation point)

無向グラフ $G = (V, E)$ において，グラフ $(V - \lbrace v \rbrace, E)$ が非連結となる頂点 $v$ である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Lowlink<CostType>(graph)`|無向グラフ $\mathrm{graph}$ の lowlink を考える．||
|`graph`|無向グラフ||
|`order[i]`|頂点 $i$ の訪問時刻||
|`lowlink`|lowlink||
|`ap`|関節点||
|`bridge`|橋|多重辺に対応していない．|


## 参考

- http://kagamiz.hatenablog.com/entry/2013/10/05/005213


## Verified

- [橋](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082818/emthrm/C++14)
- [関節点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_A/review/4082810/emthrm/C++14)
