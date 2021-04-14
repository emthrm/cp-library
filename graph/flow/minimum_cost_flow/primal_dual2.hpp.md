---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md
    document_title: "\u4E3B\u53CC\u5BFE\u6CD52"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/primal_dual2.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\r\n * @brief \u4E3B\u53CC\u5BFE\u6CD52\r\n * @docs docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <functional>\r\n\
    #include <limits>\r\n#include <queue>\r\n#include <tuple>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T, typename U>\r\nstruct PrimalDual2\
    \ {\r\n  struct Edge {\r\n    int dst, rev;\r\n    T cap;\r\n    U cost;\r\n \
    \   Edge(int dst, T cap, U cost, int rev) : dst(dst), cap(cap), cost(cost), rev(rev)\
    \ {}\r\n  };\r\n\r\n  const U uinf;\r\n  std::vector<std::vector<Edge>> graph;\r\
    \n\r\n  PrimalDual2(int n, const U uinf = std::numeric_limits<U>::max()) : n(n),\
    \ uinf(uinf), graph(n + 2), d(n + 2, 0) {}\r\n\r\n  void add_edge(int src, int\
    \ dst, T cap, U cost) {\r\n    if (cost < 0) {\r\n      d[src] -= cap;\r\n   \
    \   d[dst] += cap;\r\n      res += cost * cap;\r\n      std::swap(src, dst);\r\
    \n      cost = -cost;\r\n    }\r\n    graph[src].emplace_back(dst, cap, cost,\
    \ graph[dst].size());\r\n    graph[dst].emplace_back(src, 0, -cost, graph[src].size()\
    \ - 1);\r\n  }\r\n\r\n  U minimum_cost_flow() {\r\n    T flow = 0;\r\n    for\
    \ (int i = 0; i < n; ++i) {\r\n      if (d[i] > 0) {\r\n        add_edge(n, i,\
    \ d[i], 0);\r\n        flow += d[i];\r\n      } else if (d[i] < 0) {\r\n     \
    \   add_edge(i, n + 1, -d[i], 0);\r\n      }\r\n    }\r\n    std::vector<int>\
    \ prev_v(n + 2, -1), prev_e(n + 2, -1);\r\n    std::vector<U> dist(n + 2), potential(n\
    \ + 2, 0);\r\n    std::priority_queue<std::pair<U, int>, std::vector<std::pair<U,\
    \ int>>, std::greater<std::pair<U, int>>> que;\r\n    while (flow > 0) {\r\n \
    \     std::fill(dist.begin(), dist.end(), uinf);\r\n      dist[n] = 0;\r\n   \
    \   que.emplace(0, n);\r\n      while (!que.empty()) {\r\n        U fst; int ver;\
    \ std::tie(fst, ver) = que.top(); que.pop();\r\n        if (dist[ver] < fst) continue;\r\
    \n        for (int i = 0; i < graph[ver].size(); ++i) {\r\n          const Edge\
    \ &e = graph[ver][i];\r\n          U nx = dist[ver] + e.cost + potential[ver]\
    \ - potential[e.dst];\r\n          if (e.cap > 0 && dist[e.dst] > nx) {\r\n  \
    \          dist[e.dst] = nx;\r\n            prev_v[e.dst] = ver;\r\n         \
    \   prev_e[e.dst] = i;\r\n            que.emplace(dist[e.dst], e.dst);\r\n   \
    \       }\r\n        }\r\n      }\r\n      if (dist[n + 1] == uinf) return uinf;\r\
    \n      for (int i = 0; i < n + 2; ++i) {\r\n        if (dist[i] != uinf) potential[i]\
    \ += dist[i];\r\n      }\r\n      T f = flow;\r\n      for (int v = n + 1; v !=\
    \ n; v = prev_v[v]) {\r\n        if (graph[prev_v[v]][prev_e[v]].cap < f) f =\
    \ graph[prev_v[v]][prev_e[v]].cap;\r\n      }\r\n      flow -= f;\r\n      res\
    \ += potential[n + 1] * f;\r\n      for (int v = n + 1; v != n; v = prev_v[v])\
    \ {\r\n        Edge &e = graph[prev_v[v]][prev_e[v]];\r\n        e.cap -= f;\r\
    \n        graph[v][e.rev].cap += f;\r\n      }\r\n    }\r\n    return res;\r\n\
    \  }\r\n\r\n  U minimum_cost_flow(int s, int t, T flow) {\r\n    d[s] += flow;\r\
    \n    d[t] -= flow;\r\n    return minimum_cost_flow();\r\n  }\r\n\r\nprivate:\r\
    \n  int n;\r\n  U res = 0;\r\n  std::vector<T> d;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/minimum_cost_flow/primal_dual2.hpp
  requiredBy: []
  timestamp: '2021-03-15 23:38:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
documentation_of: graph/flow/minimum_cost_flow/primal_dual2.hpp
layout: document
redirect_from:
- /library/graph/flow/minimum_cost_flow/primal_dual2.hpp
- /library/graph/flow/minimum_cost_flow/primal_dual2.hpp.html
title: "\u4E3B\u53CC\u5BFE\u6CD52"
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
|`PrimalDual<フロー, コスト>(n, ∞)`|頂点数 $N$ の主双対法を考える．||
|`uinf`|$\infty$|型はコストと等しい．|
|`graph`|残余グラフ||
|`add_edge(src, dst, cap, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$, コスト $\mathrm{cost}$ の辺を張る．||
|`minimum_cost_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せない場合は $\infty$ となる．|
|`minimum_cost_flow(s, t)`|始点 $s$ から終点 $t$ まで流量任意のフローを流すときのコストの最小値|流量は $\mathrm{tinf} - f$ である．|
|`min_cost_max_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流したいときの最小費用最大流|返り値は最大流と最小費用である．|

- 主双対法2

||説明|備考|
|:--:|:--:|:--:|
|`PrimalDual2<フロー, コスト>(n, ∞)`|頂点数 $N$ の主双対法2を考える．||
|`uinf`|$\infty$|型はコストと等しい．|
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
