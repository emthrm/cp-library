---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md
    document_title: "\u6700\u5C0F\u8CBB\u7528 $\\boldsymbol{b}$-\u30D5\u30ED\u30FC\
      \ \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\n * @brief \u6700\u5C0F\u8CBB\u7528 $\\boldsymbol{b}$-\u30D5\u30ED\u30FC\
    \ \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5\u7248\n * @docs docs/graph/flow/minimum_cost_flow/minimum_cost_flow.md\n\
    \ */\n\n#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <limits>\n#include <numeric>\n#include <queue>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\ntemplate <typename T, typename U>\nstruct MinimumCostBFlow\
    \ {\n  struct Edge {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit\
    \ Edge(const int dst, const T cap, const U cost, const int rev)\n        : dst(dst),\
    \ cap(cap), cost(cost), rev(rev) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit MinimumCostBFlow(const int n,\n                       \
    \     const U uinf = std::numeric_limits<U>::max())\n      : uinf(uinf), graph(n\
    \ + 2), n(n), res(0), b(n + 2, 0) {}\n\n  void add_edge(int src, int dst, const\
    \ T cap, U cost) {\n    if (cost < 0) {\n      b[src] -= cap;\n      b[dst] +=\
    \ cap;\n      res += cost * cap;\n      std::swap(src, dst);\n      cost = -cost;\n\
    \    }\n    graph[src].emplace_back(dst, cap, cost, graph[dst].size());\n    graph[dst].emplace_back(src,\
    \ 0, -cost, graph[src].size() - 1);\n  }\n\n  void supply_or_demand(const int\
    \ ver, const T amount) { b[ver] += amount; }\n\n  U solve() {\n    assert(std::accumulate(b.begin(),\
    \ b.end(), static_cast<T>(0)) == 0);\n    T flow = 0;\n    for (int i = 0; i <\
    \ n; ++i) {\n      if (b[i] > 0) {\n        add_edge(n, i, b[i], 0);\n       \
    \ flow += b[i];\n      } else if (b[i] < 0) {\n        add_edge(i, n + 1, -b[i],\
    \ 0);\n      }\n    }\n    std::vector<int> prev_v(n + 2, -1), prev_e(n + 2, -1);\n\
    \    std::vector<U> dist(n + 2), potential(n + 2, 0);\n    std::priority_queue<std::pair<U,\
    \ int>, std::vector<std::pair<U, int>>,\n                        std::greater<std::pair<U,\
    \ int>>> que;\n    while (flow > 0) {\n      std::fill(dist.begin(), dist.end(),\
    \ uinf);\n      dist[n] = 0;\n      que.emplace(0, n);\n      while (!que.empty())\
    \ {\n        U d;\n        int ver;\n        std::tie(d, ver) = que.top();\n \
    \       que.pop();\n        if (d > dist[ver]) continue;\n        for (int i =\
    \ 0; i < graph[ver].size(); ++i) {\n          const Edge& e = graph[ver][i];\n\
    \          const U nxt = dist[ver] + e.cost + potential[ver] - potential[e.dst];\n\
    \          if (e.cap > 0 && dist[e.dst] > nxt) {\n            dist[e.dst] = nxt;\n\
    \            prev_v[e.dst] = ver;\n            prev_e[e.dst] = i;\n          \
    \  que.emplace(dist[e.dst], e.dst);\n          }\n        }\n      }\n      if\
    \ (dist[n + 1] == uinf) return uinf;\n      for (int i = 0; i < n + 2; ++i) {\n\
    \        if (dist[i] != uinf) potential[i] += dist[i];\n      }\n      T f = flow;\n\
    \      for (int v = n + 1; v != n; v = prev_v[v]) {\n        f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\n\
    \      }\n      flow -= f;\n      res += potential[n + 1] * f;\n      for (int\
    \ v = n + 1; v != n; v = prev_v[v]) {\n        Edge& e = graph[prev_v[v]][prev_e[v]];\n\
    \        e.cap -= f;\n        graph[v][e.rev].cap += f;\n      }\n    }\n    return\
    \ res;\n  }\n\n  U solve(const int s, const int t, const T flow) {\n    supply_or_demand(s,\
    \ flow);\n    supply_or_demand(t, -flow);\n    return solve();\n  }\n\n private:\n\
    \  int n;\n  U res;\n  std::vector<T> b;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
documentation_of: graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
layout: document
redirect_from:
- /library/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
- /library/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp.html
title: "\u6700\u5C0F\u8CBB\u7528 $\\boldsymbol{b}$-\u30D5\u30ED\u30FC \u6700\u77ED\
  \u8DEF\u53CD\u5FA9\u6CD5\u7248"
---
# 最小費用流 (minimum cost flow)


## 計算量

最大流の流量を $F$ とおく．

||計算量|
|:--:|:--:|
|最小費用 $s$-$t$-フロー 最短路反復法 (successive shortest path algorithm) 版|$O(\lvert V \rvert \lvert E \rvert + F \lvert E \rvert \log{\lvert V \rvert})$|
|最小費用 $\boldsymbol{b}$-フロー 最短路反復法版|コスト負の辺の容量の総和を $F^{\prime}$ とおくと $O((F + F^{\prime})\lvert E \rvert \log{\lvert V \rvert})$．|


## 使用法

- 最小費用 $s$-$t$-フロー 最短路反復法版

||説明|備考|
|:--:|:--:|:--:|
|`MinimumCostSTFlow<フロー, コスト>(n, ∞)`|頂点数 $N$ の最小費用 $s$-$t$-フローを考える．||
|`uinf`|$\infty$|型はコストと等しい．|
|`graph`|残余グラフ||
|`add_edge(src, dst, cap, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$, コスト $\mathrm{cost}$ の辺を加える．||
|`solve(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときの最小コスト|流せないときは $\infty$ となる．|
|`solve(s, t)`|始点 $s$ から終点 $t$ まで流量任意のフローを流すときの最小コスト|流量は $\mathrm{tinf} - \mathrm{flow}$ である．|
|`minimum_cost_maximum_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ 以下のフローを流すときの最小費用最大流|返り値は最大流と最小費用である．|

- 最小費用 $\boldsymbol{b}$-フロー 最短路反復法版

||説明|備考|
|:--:|:--:|:--:|
|`MinimumCostBFlow<フロー, コスト>(n, ∞)`|頂点数 $N$ の最小費用 $\boldsymbol{b}$-フローを考える．||
|`uinf`|$\infty$|型はコストと等しい．|
|`graph`|残余グラフ||
|`add_edge(src, dst, cap, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$, コスト $\mathrm{cost}$ の辺を加える．||
|`supply_or_demand(ver, amount)`|$b_{\mathrm{ver}} \gets b_{\mathrm{ver}} + \mathrm{amount}$||
|`solve()`|最小費用循環流|流せないときは $\infty$ となる．|
|`solve(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときの最小コスト|流せないときは $\infty$ となる．|


## 注意

流量正の辺の合計コストの和を最小化する問題を最小費用流で解くことはできない．


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.199-205，マイナビ出版（2012）

最小費用 $s$-$t$-フロー 最短路反復法版
- http://sigma425.hatenablog.com/entry/2014/10/12/122018

最小費用 $\boldsymbol{b}$-フロー 最短路反復法版
- https://snuke.hatenablog.com/entry/2017/06/07/115821


## ToDo

- 容量スケーリング
  - https://misawa.github.io/others/flow/lets_use_capacity_scaling.html
- 最小費用 $\boldsymbol{b}$-フロー
  - https://misawa.github.io/others/flow/library_design.html
  - https://twitter.com/Mi_Sawa/status/1283768916775321601
  - https://noshi91.hatenablog.com/entry/2021/12/15/012019
  - https://judge.yosupo.jp/problem/min_cost_b_flow
- グラフにコスト負の閉路が存在するとき


## Verified

- 最小費用 $s$-$t$-フロー 最短路反復法版
  - [`solve(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_B/review/4092721/emthrm/C++14)
  - [`solve(s, t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2293/review/4085999/emthrm/C++14)
  - [`minimum_cost_maximum_flow(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1088/review/4086009/emthrm/C++14)
- [最小費用 $\boldsymbol{b}$-フロー 最短路反復法版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14)
