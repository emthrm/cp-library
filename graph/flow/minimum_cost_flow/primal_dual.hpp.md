---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/flow/matching/weighted_bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
      \u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
      \u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\u30C3\
      \u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/primal_dual.1.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u4E3B\
      \u53CC\u5BFE\u6CD5 (minimum_cost_flow(s, t, flow))"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/primal_dual.2.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u4E3B\
      \u53CC\u5BFE\u6CD5 (minimum_cost_flow(s, t))"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/primal_dual.3.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u4E3B\
      \u53CC\u5BFE\u6CD5 (min_cost_max_flow(s, t, flow))"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.01.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md
    document_title: "\u4E3B\u53CC\u5BFE\u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/primal_dual.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\r\n * @brief \u4E3B\u53CC\u5BFE\u6CD5\r\n * @docs docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include\
    \ <functional>\r\n#include <queue>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T, typename U>\r\nstruct PrimalDual {\r\n  struct Edge\
    \ {\r\n    int dst, rev;\r\n    T cap;\r\n    U cost;\r\n    Edge(int dst, T cap,\
    \ U cost, int rev) : dst(dst), cap(cap), cost(cost), rev(rev) {}\r\n  };\r\n\r\
    \n  std::vector<std::vector<Edge>> graph;\r\n\r\n  PrimalDual(int n, const T TINF,\
    \ const U UINF) : n(n), TINF(TINF), UINF(UINF), graph(n), prev_v(n, -1), prev_e(n,\
    \ -1), potential(n, 0), dist(n) {}\r\n\r\n  void add_edge(int src, int dst, T\
    \ cap, U cost) {\r\n    has_negative_edge |= cost < 0;\r\n    graph[src].emplace_back(dst,\
    \ cap, cost, graph[dst].size());\r\n    graph[dst].emplace_back(src, 0, -cost,\
    \ graph[src].size() - 1);\r\n  }\r\n\r\n  U minimum_cost_flow(int s, int t, T\
    \ flow) {\r\n    U res = 0;\r\n    if (has_negative_edge) {\r\n      bellman_ford(s);\r\
    \n      if (dist[t] == UINF) return UINF;\r\n      res += calc(s, t, flow);\r\n\
    \    }\r\n    while (flow > 0) {\r\n      dijkstra(s);\r\n      if (dist[t] ==\
    \ UINF) return UINF;\r\n      res += calc(s, t, flow);\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  U minimum_cost_flow(int s, int t) {\r\n    U res = 0;\r\
    \n    bellman_ford(s);\r\n    if (potential[t] >= 0 || dist[t] == UINF) return\
    \ res;\r\n    T tmp = TINF;\r\n    res += calc(s, t, tmp);\r\n    while (true)\
    \ {\r\n      dijkstra(s);\r\n      if (potential[t] >= 0 || dist[t] == UINF) return\
    \ res;\r\n      res += calc(s, t, tmp);\r\n    }\r\n  }\r\n\r\n  std::pair<T,\
    \ U> min_cost_max_flow(int s, int t, T flow) {\r\n    T mx = flow;\r\n    U cost\
    \ = 0;\r\n    if (has_negative_edge) {\r\n      bellman_ford(s);\r\n      if (dist[t]\
    \ == UINF) return {mx - flow, cost};\r\n      cost += calc(s, t, flow);\r\n  \
    \  }\r\n    while (flow > 0) {\r\n      dijkstra(s);\r\n      if (dist[t] == UINF)\
    \ return {mx - flow, cost};\r\n      cost += calc(s, t, flow);\r\n    }\r\n  \
    \  return {mx - flow, cost};\r\n  }\r\n\r\nprivate:\r\n  using Pui = std::pair<U,\
    \ int>;\r\n\r\n  int n;\r\n  const T TINF;\r\n  const U UINF;\r\n  bool has_negative_edge\
    \ = false;\r\n  std::vector<int> prev_v, prev_e;\r\n  std::vector<U> potential,\
    \ dist;\r\n  std::priority_queue<Pui, std::vector<Pui>, std::greater<Pui>> que;\r\
    \n\r\n  void bellman_ford(int s) {\r\n    std::fill(dist.begin(), dist.end(),\
    \ UINF);\r\n    dist[s] = 0;\r\n    bool is_updated = true;\r\n    for (int step\
    \ = 0; step < n; ++step) {\r\n      is_updated = false;\r\n      for (int i =\
    \ 0; i < n; ++i) {\r\n        if (dist[i] == UINF) continue;\r\n        for (int\
    \ j = 0; j < graph[i].size(); ++j) {\r\n          Edge e = graph[i][j];\r\n  \
    \        if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {\r\n            dist[e.dst]\
    \ = dist[i] + e.cost;\r\n            prev_v[e.dst] = i;\r\n            prev_e[e.dst]\
    \ = j;\r\n            is_updated = true;\r\n          }\r\n        }\r\n     \
    \ }\r\n      if (!is_updated) break;\r\n    }\r\n    assert(!is_updated);\r\n\
    \    for (int i = 0; i < n; ++i) {\r\n      if (dist[i] != UINF) potential[i]\
    \ += dist[i];\r\n    }\r\n  }\r\n\r\n  void dijkstra(int s) {\r\n    std::fill(dist.begin(),\
    \ dist.end(), UINF);\r\n    dist[s] = 0;\r\n    que.emplace(0, s);\r\n    while\
    \ (!que.empty()) {\r\n      Pui pr = que.top(); que.pop();\r\n      int ver =\
    \ pr.second;\r\n      if (dist[ver] < pr.first) continue;\r\n      for (int i\
    \ = 0; i < graph[ver].size(); ++i) {\r\n        Edge e = graph[ver][i];\r\n  \
    \      U nx = dist[ver] + e.cost + potential[ver] - potential[e.dst];\r\n    \
    \    if (e.cap > 0 && dist[e.dst] > nx) {\r\n          dist[e.dst] = nx;\r\n \
    \         prev_v[e.dst] = ver;\r\n          prev_e[e.dst] = i;\r\n          que.emplace(dist[e.dst],\
    \ e.dst);\r\n        }\r\n      }\r\n    }\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n      if (dist[i] != UINF) potential[i] += dist[i];\r\n    }\r\n  }\r\n\
    \r\n  U calc(int s, int t, T &flow) {\r\n    T f = flow;\r\n    for (int v = t;\
    \ v != s; v = prev_v[v]) f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\r\n\
    \    flow -= f;\r\n    for (int v = t; v != s; v = prev_v[v]) {\r\n      Edge\
    \ &e = graph[prev_v[v]][prev_e[v]];\r\n      e.cap -= f;\r\n      graph[v][e.rev].cap\
    \ += f;\r\n    }\r\n    return potential[t] * f;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/minimum_cost_flow/primal_dual.hpp
  requiredBy:
  - graph/flow/matching/weighted_bipartite_matching.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/flow/minimum_cost_flow/primal_dual.3.test.cpp
  - test/graph/flow/minimum_cost_flow/primal_dual.1.test.cpp
  - test/graph/flow/minimum_cost_flow/primal_dual.2.test.cpp
  - test/graph/flow/matching/weighted_bipartite_matching.test.cpp
  - test/math/bigint.01.test.cpp
documentation_of: graph/flow/minimum_cost_flow/primal_dual.hpp
layout: document
redirect_from:
- /library/graph/flow/minimum_cost_flow/primal_dual.hpp
- /library/graph/flow/minimum_cost_flow/primal_dual.hpp.html
title: "\u4E3B\u53CC\u5BFE\u6CD5"
---
# 最小費用流 (minimum cost flow)

ある始点からある終点まで特定量のフローを流すためにかかるコストの最小値である．

- 主双対法 (primal-dual method)


## 計算量

最大流の流量を $F$ とおく．

||計算量|
|:--:|:--:|
|主双対法|$O(\lvert V \rvert \lvert E \rvert + F \lvert E \rvert \log{\lvert V \rvert})$|
|主双対法2|コスト負の辺の容量の総和を $F^{\prime}$ とおくと $O((F + F^{\prime})\lvert E \rvert \log{\lvert V \rvert})$．|


## 使用法

- 主双対法

||説明|備考|
|:--:|:--:|:--:|
|`PrimalDual<フロー, コスト>(n, ∞, ∞)`|頂点数 $N$ の主双対法を考える．||
|`graph`|残余グラフ||
|`add_edge(src, dst, cap, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$, コスト $\mathrm{cost}$ の辺を張る．||
|`minimum_cost_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せない場合は $\infty$ となる．|
|`minimum_cost_flow(s, t)`|始点 $s$ から終点 $t$ まで流量任意のフローを流すときのコストの最小値|流量は $\mathrm{TINF} - \mathrm{tmp}$ である．|
|`min_cost_max_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流したいときの最小費用最大流 (最大流, 最小費用)||

- 主双対法2

||説明|備考|
|:--:|:--:|:--:|
|`PrimalDual2<フロー, コスト>(n, ∞, ∞)`|頂点数 $N$ の主双対法2を考える．||
|`graph`|残余グラフ||
|`add_edge(src, dst, cap, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$, コスト $\mathrm{cost}$ の辺を張る．||
|`minimum_cost_flow()`|最小費用循環流|流せない場合は $\infty$ となる．|
|`minimum_cost_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せない場合は $\infty$ となる．|


## 注意

流量正の辺の合計コストの和を最小化する問題を最小費用流で解くことはできない．


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.199-205

主双対法
- http://sigma425.hatenablog.com/entry/2014/10/12/122018

主双対法2
- https://snuke.hatenablog.com/entry/2017/06/07/115821


## ToDo

- グラフにコスト負の閉路が存在する場合
- 容量スケーリング
  - https://misawa.github.io/others/flow/lets_use_capacity_scaling.html
- 最小費用 $b$-フロー
  - https://misawa.github.io/others/flow/library_design.html
  - https://twitter.com/Mi_Sawa/status/1283768916775321601
  - https://judge.yosupo.jp/problem/min_cost_b_flow


## Verified

- 主双対法
  - [`minimum_cost_flow(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_B/review/4092721/emthrm/C++14)
  - [`minimum_cost_flow(s, t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2293/review/4085999/emthrm/C++14)
  - [`min_cost_max_flow(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1088/review/4086009/emthrm/C++14)
- [主双対法2](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14)
