---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
      \u30DE\u30C3\u30C1\u30F3\u30B0"
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E8C\
      \u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\u30C3\
      \u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\u5FA9\
      \u6CD5\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.2.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\u5FA9\
      \u6CD5\u7248\uFF08\u4EFB\u610F\u6D41\u91CF\uFF09"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\u5FA9\
      \u6CD5\u7248\uFF08\u6700\u5C0F\u8CBB\u7528\u6700\u5927\u6D41\uFF09"
  - icon: ':heavy_check_mark:'
    path: test/math/bigint.01.test.cpp
    title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T, typename U>\nstruct MinimumCostSTFlow {\n\
    \  struct Edge {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit Edge(const\
    \ int dst, const T cap, const U cost, const int rev)\n        : dst(dst), rev(rev),\
    \ cap(cap), cost(cost) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit MinimumCostSTFlow(const int n,\n                      \
    \       const U uinf = std::numeric_limits<U>::max())\n      : uinf(uinf), graph(n),\
    \ tinf(std::numeric_limits<T>::max()), n(n),\n        has_negative_edge(false),\
    \ prev_v(n, -1), prev_e(n, -1), dist(n),\n        potential(n, 0) {}\n\n  void\
    \ add_edge(const int src, const int dst, const T cap, const U cost) {\n    has_negative_edge\
    \ |= cost < 0;\n    graph[src].emplace_back(dst, cap, cost, graph[dst].size());\n\
    \    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);\n  }\n\n \
    \ U solve(const int s, const int t, T flow) {\n    if (flow == 0) [[unlikely]]\
    \ return 0;\n    U res = 0;\n    has_negative_edge ? bellman_ford(s) : dijkstra(s);\n\
    \    while (true) {\n      if (dist[t] == uinf) return uinf;\n      res += calc(s,\
    \ t, &flow);\n      if (flow == 0) break;\n      dijkstra(s);\n    }\n    return\
    \ res;\n  }\n\n  U solve(const int s, const int t) {\n    U res = 0;\n    T flow\
    \ = tinf;\n    bellman_ford(s);\n    while (potential[t] < 0 && dist[t] != uinf)\
    \ {\n      res += calc(s, t, &flow);\n      dijkstra(s);\n    }\n    return res;\n\
    \  }\n\n  std::pair<T, U> minimum_cost_maximum_flow(const int s, const int t,\n\
    \                                            const T flow) {\n    if (flow ==\
    \ 0) [[unlikely]] return {0, 0};\n    T f = flow;\n    U cost = 0;\n    has_negative_edge\
    \ ? bellman_ford(s) : dijkstra(s);\n    while (dist[t] != uinf) {\n      cost\
    \ += calc(s, t, &f);\n      if (f == 0) break;\n      dijkstra(s);\n    }\n  \
    \  return {flow - f, cost};\n  }\n\n private:\n  const T tinf;\n  const int n;\n\
    \  bool has_negative_edge;\n  std::vector<int> prev_v, prev_e;\n  std::vector<U>\
    \ dist, potential;\n  std::priority_queue<std::pair<U, int>, std::vector<std::pair<U,\
    \ int>>,\n                      std::greater<std::pair<U, int>>> que;\n\n  void\
    \ bellman_ford(const int s) {\n    std::fill(dist.begin(), dist.end(), uinf);\n\
    \    dist[s] = 0;\n    bool is_updated = true;\n    for (int step = 0; step <\
    \ n && is_updated; ++step) {\n      is_updated = false;\n      for (int i = 0;\
    \ i < n; ++i) {\n        if (dist[i] == uinf) continue;\n        for (int j =\
    \ 0; std::cmp_less(j, graph[i].size()); ++j) {\n          const Edge& e = graph[i][j];\n\
    \          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {\n            dist[e.dst]\
    \ = dist[i] + e.cost;\n            prev_v[e.dst] = i;\n            prev_e[e.dst]\
    \ = j;\n            is_updated = true;\n          }\n        }\n      }\n    }\n\
    \    assert(!is_updated);\n    for (int i = 0; i < n; ++i) {\n      if (dist[i]\
    \ != uinf) potential[i] += dist[i];\n    }\n  }\n\n  void dijkstra(const int s)\
    \ {\n    std::fill(dist.begin(), dist.end(), uinf);\n    dist[s] = 0;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (dist[ver] < d) continue;\n      for (int i = 0; std::cmp_less(i,\
    \ graph[ver].size()); ++i) {\n        const Edge& e = graph[ver][i];\n       \
    \ const U nxt = dist[ver] + e.cost + potential[ver] - potential[e.dst];\n    \
    \    if (e.cap > 0 && dist[e.dst] > nxt) {\n          dist[e.dst] = nxt;\n   \
    \       prev_v[e.dst] = ver;\n          prev_e[e.dst] = i;\n          que.emplace(dist[e.dst],\
    \ e.dst);\n        }\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n    \
    \  if (dist[i] != uinf) potential[i] += dist[i];\n    }\n  }\n\n  U calc(const\
    \ int s, const int t, T* flow) {\n    T f = *flow;\n    for (int v = t; v != s;\
    \ v = prev_v[v]) {\n      f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\n\
    \    }\n    *flow -= f;\n    for (int v = t; v != s; v = prev_v[v]) {\n      Edge&\
    \ e = graph[prev_v[v]][prev_e[v]];\n      e.cap -= f;\n      graph[v][e.rev].cap\
    \ += f;\n    }\n    return potential[t] * f;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_S_T_FLOW_HPP_\n\
    #define EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_S_T_FLOW_HPP_\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\
    \ntemplate <typename T, typename U>\nstruct MinimumCostSTFlow {\n  struct Edge\
    \ {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit Edge(const int dst,\
    \ const T cap, const U cost, const int rev)\n        : dst(dst), rev(rev), cap(cap),\
    \ cost(cost) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>> graph;\n\
    \n  explicit MinimumCostSTFlow(const int n,\n                             const\
    \ U uinf = std::numeric_limits<U>::max())\n      : uinf(uinf), graph(n), tinf(std::numeric_limits<T>::max()),\
    \ n(n),\n        has_negative_edge(false), prev_v(n, -1), prev_e(n, -1), dist(n),\n\
    \        potential(n, 0) {}\n\n  void add_edge(const int src, const int dst, const\
    \ T cap, const U cost) {\n    has_negative_edge |= cost < 0;\n    graph[src].emplace_back(dst,\
    \ cap, cost, graph[dst].size());\n    graph[dst].emplace_back(src, 0, -cost, graph[src].size()\
    \ - 1);\n  }\n\n  U solve(const int s, const int t, T flow) {\n    if (flow ==\
    \ 0) [[unlikely]] return 0;\n    U res = 0;\n    has_negative_edge ? bellman_ford(s)\
    \ : dijkstra(s);\n    while (true) {\n      if (dist[t] == uinf) return uinf;\n\
    \      res += calc(s, t, &flow);\n      if (flow == 0) break;\n      dijkstra(s);\n\
    \    }\n    return res;\n  }\n\n  U solve(const int s, const int t) {\n    U res\
    \ = 0;\n    T flow = tinf;\n    bellman_ford(s);\n    while (potential[t] < 0\
    \ && dist[t] != uinf) {\n      res += calc(s, t, &flow);\n      dijkstra(s);\n\
    \    }\n    return res;\n  }\n\n  std::pair<T, U> minimum_cost_maximum_flow(const\
    \ int s, const int t,\n                                            const T flow)\
    \ {\n    if (flow == 0) [[unlikely]] return {0, 0};\n    T f = flow;\n    U cost\
    \ = 0;\n    has_negative_edge ? bellman_ford(s) : dijkstra(s);\n    while (dist[t]\
    \ != uinf) {\n      cost += calc(s, t, &f);\n      if (f == 0) break;\n      dijkstra(s);\n\
    \    }\n    return {flow - f, cost};\n  }\n\n private:\n  const T tinf;\n  const\
    \ int n;\n  bool has_negative_edge;\n  std::vector<int> prev_v, prev_e;\n  std::vector<U>\
    \ dist, potential;\n  std::priority_queue<std::pair<U, int>, std::vector<std::pair<U,\
    \ int>>,\n                      std::greater<std::pair<U, int>>> que;\n\n  void\
    \ bellman_ford(const int s) {\n    std::fill(dist.begin(), dist.end(), uinf);\n\
    \    dist[s] = 0;\n    bool is_updated = true;\n    for (int step = 0; step <\
    \ n && is_updated; ++step) {\n      is_updated = false;\n      for (int i = 0;\
    \ i < n; ++i) {\n        if (dist[i] == uinf) continue;\n        for (int j =\
    \ 0; std::cmp_less(j, graph[i].size()); ++j) {\n          const Edge& e = graph[i][j];\n\
    \          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {\n            dist[e.dst]\
    \ = dist[i] + e.cost;\n            prev_v[e.dst] = i;\n            prev_e[e.dst]\
    \ = j;\n            is_updated = true;\n          }\n        }\n      }\n    }\n\
    \    assert(!is_updated);\n    for (int i = 0; i < n; ++i) {\n      if (dist[i]\
    \ != uinf) potential[i] += dist[i];\n    }\n  }\n\n  void dijkstra(const int s)\
    \ {\n    std::fill(dist.begin(), dist.end(), uinf);\n    dist[s] = 0;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (dist[ver] < d) continue;\n      for (int i = 0; std::cmp_less(i,\
    \ graph[ver].size()); ++i) {\n        const Edge& e = graph[ver][i];\n       \
    \ const U nxt = dist[ver] + e.cost + potential[ver] - potential[e.dst];\n    \
    \    if (e.cap > 0 && dist[e.dst] > nxt) {\n          dist[e.dst] = nxt;\n   \
    \       prev_v[e.dst] = ver;\n          prev_e[e.dst] = i;\n          que.emplace(dist[e.dst],\
    \ e.dst);\n        }\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n    \
    \  if (dist[i] != uinf) potential[i] += dist[i];\n    }\n  }\n\n  U calc(const\
    \ int s, const int t, T* flow) {\n    T f = *flow;\n    for (int v = t; v != s;\
    \ v = prev_v[v]) {\n      f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\n\
    \    }\n    *flow -= f;\n    for (int v = t; v != s; v = prev_v[v]) {\n      Edge&\
    \ e = graph[prev_v[v]][prev_e[v]];\n      e.cap -= f;\n      graph[v][e.rev].cap\
    \ += f;\n    }\n    return potential[t] * f;\n  }\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_S_T_FLOW_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  requiredBy:
  - include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/math/bigint.01.test.cpp
  - test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.2.test.cpp
  - test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
  - test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
  - test/graph/flow/matching/weighted_bipartite_matching.test.cpp
documentation_of: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
layout: document
title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC (minimum cost $s$-$t$-flow)\
  \ \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5 (successive shortest path algorithm) \u7248"
---

# 最小費用流 (minimum cost flow)


## 計算量

最大流の流量を $F$ とおく。

||計算量|
|:--|:--|
|最小費用 $s$-$t$-フロー 最短路反復法版|$O(\lvert V \rvert \lvert E \rvert + F \lvert E \rvert \log{\lvert V \rvert})$|
|最小費用 $\boldsymbol{b}$-フロー 最短路反復法版|コスト負の辺の容量の総和を $F^{\prime}$ とおくと $O((F + F^{\prime})\lvert E \rvert \log{\lvert V \rvert})$。|


## 仕様

### 最小費用 $s$-$t$-フロー 最短路反復法版

```cpp
template <typename T, typename U>
struct MinimumCostSTFlow;
```

- `T`：容量を表す型
- `U`：コストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const U uinf`|$\infty$|
|`std::vector<std::vector<Edge>> graph`|残余グラフ|

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit MinimumCostSTFlow(const int n, const U uinf = std::numeric_limits<U>::max());`|頂点数 $N$ のオブジェクトを構築する。||
|`void add_edge(const int src, const int dst, const T cap, const U cost);`|始点 $\mathrm{src}$、終点 $\mathrm{dst}$、容量 $\mathrm{cap}$、コスト $\mathrm{cost}$ の辺を加える。||
|`U solve(const int s, const int t, T flow);`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときの最小コスト。ただし流せないときは `uinf` を返す。|
|`U solve(const int s, const int t);`|始点 $s$ から終点 $t$ まで流量任意のフローを流すときの最小コスト|流量は $\mathrm{tinf} - \mathrm{flow}$ である。|
|`std::pair<T, U> minimum_cost_maximum_flow(const int s, const int t, const T flow);`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ 以下のフローを流すときの最小費用最大流。最大流と最小費用の組を返す。||

#### メンバ型

|名前|説明|
|:--|:--|
|`Edge`|辺を表す構造体|

```cpp
struct Edge;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`int dst`|終点|
|`int rev`|頂点 $\mathrm{dst}$ における逆辺のインデックス|
|`T cap`|残りの容量|
|`U cost`|流量 $1$ のフローを流すときのコスト|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Edge(const int dst, const T cap, const U cost, const int rev);`|コンストラクタ|


### 最小費用 $\boldsymbol{b}$-フロー 最短路反復法版

```cpp
template <typename T, typename U>
struct MinimumCostBFlow;
```

- `T`：容量を表す型
- `U`：コストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const U uinf`|$\infty$|
|`std::vector<std::vector<Edge>> graph`|残余グラフ|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit MinimumCostBFlow(const int n, const U uinf = std::numeric_limits<U>::max());`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(int src, int dst, const T cap, U cost);`|始点 $\mathrm{src}$、終点 $\mathrm{dst}$、容量 $\mathrm{cap}$、コスト $\mathrm{cost}$ の辺を加える。|
|`void supply_or_demand(const int ver, const T amount);`|$b_{\mathrm{ver}} \gets b_{\mathrm{ver}} + \mathrm{amount}$|
|`U solve();`|最小費用循環流。ただし流せないときは `uinf` を返す。|
|`U solve(const int s, const int t, const T flow);`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときの最小コスト。ただし流せないときは `uinf` を返す。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Edge`|辺を表す構造体|

```cpp
struct Edge;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`int dst`|終点|
|`int rev`|頂点 $\mathrm{dst}$ における逆辺のインデックス|
|`T cap`|残りの容量|
|`U cost`|流量 $1$ のフローを流すときのコスト|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Edge(const int dst, const T cap, const U cost, const int rev);`|コンストラクタ|


## 注意

流量正の辺の合計コストの和を最小化する問題を最小費用流で解くことはできない。


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.199-205，マイナビ出版（2012）

最小費用 $s$-$t$-フロー 最短路反復法版
- http://sigma425.hatenablog.com/entry/2014/10/12/122018

最小費用 $\boldsymbol{b}$-フロー 最短路反復法版
- https://snuke.hatenablog.com/entry/2017/06/07/115821


## TODO

- 容量スケーリング
  - https://misawa.github.io/others/flow/lets_use_capacity_scaling.html
- 最小費用 $\boldsymbol{b}$-フロー
  - https://misawa.github.io/others/flow/library_design.html
  - https://twitter.com/Mi_Sawa/status/1283768916775321601
  - https://noshi91.hatenablog.com/entry/2021/12/15/012019
  - https://judge.yosupo.jp/problem/min_cost_b_flow
- グラフにコスト負の閉路が存在するとき


## Submissons

- 最小費用 $s$-$t$-フロー 最短路反復法版
  - [`solve(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_B/review/4092721/emthrm/C++14)
  - [`solve(s, t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2293/review/4085999/emthrm/C++14)
  - [`minimum_cost_maximum_flow(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1088/review/4086009/emthrm/C++14)
- [最小費用 $\boldsymbol{b}$-フロー 最短路反復法版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14)
