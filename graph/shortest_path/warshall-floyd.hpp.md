---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/warshall-floyd.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest_path/warshall-floyd.hpp\"\n#include <set>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct WarshallFloyd {\r\n\
    \  std::vector<std::vector<T>> graph, dist;\r\n\r\n  WarshallFloyd(const std::vector<std::vector<T>>\
    \ &graph, const T TINF) : graph(graph), dist(graph), TINF(TINF) {\r\n    n = graph.size();\r\
    \n    internal.assign(n, std::vector<int>(n, -1));\r\n    for (int k = 0; k <\
    \ n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {\r\n      if\
    \ (dist[i][j] > dist[i][k] + dist[k][j]) {\r\n        dist[i][j] = dist[i][k]\
    \ + dist[k][j];\r\n        internal[i][j] = k;\r\n      }\r\n    }\r\n  }\r\n\r\
    \n  void add(int src, int dst, T cost) {\r\n    srcs.emplace_back(src);\r\n  \
    \  dsts.emplace_back(dst);\r\n    costs.emplace_back(cost);\r\n  }\r\n\r\n  void\
    \ calc() {\r\n    std::set<int> vers;\r\n    int sz = srcs.size();\r\n    for\
    \ (int i = 0; i < sz; ++i) {\r\n      int s = srcs[i], t = dsts[i];\r\n      T\
    \ cost = costs[i];\r\n      if (cost < graph[s][t]) graph[s][t] = cost;\r\n  \
    \    if (dist[s][t] >= cost) {\r\n        dist[s][t] = cost;\r\n        internal[s][t]\
    \ = -1;\r\n      }\r\n      vers.emplace(s);\r\n      vers.emplace(t);\r\n   \
    \ }\r\n    for (int v : vers) {\r\n      for (int i = 0; i < n; ++i) for (int\
    \ j = 0; j < n; ++j) {\r\n        if (dist[i][j] > dist[i][v] + dist[v][j]) {\r\
    \n          dist[i][j] = dist[i][v] + dist[v][j];\r\n          internal[i][j]\
    \ = v;\r\n        }\r\n      }\r\n    }\r\n    srcs.clear();\r\n    dsts.clear();\r\
    \n    costs.clear();\r\n  }\r\n\r\n  bool has_negative_cycle() const {\r\n   \
    \ for (int i = 0; i < n; ++i) {\r\n      if (dist[i][i] < 0) return true;\r\n\
    \    }\r\n    return false;\r\n  }\r\n\r\n  std::vector<int> build_path(int s,\
    \ int t) const {\r\n    std::vector<int> res;\r\n    if (dist[s][t] != TINF) {\r\
    \n      build_path(s, t, res);\r\n      res.emplace_back(t);\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\nprivate:\r\n  const T TINF;\r\n  int n;\r\n  std::vector<std::vector<int>>\
    \ internal;\r\n  std::vector<int> srcs, dsts;\r\n  std::vector<T> costs;\r\n\r\
    \n  void build_path(int s, int t, std::vector<int> &path) const {\r\n    int k\
    \ = internal[s][t];\r\n    if (k == -1) {\r\n      path.emplace_back(s);\r\n \
    \   } else {\r\n      build_path(s, k, path);\r\n      build_path(k, t, path);\r\
    \n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <set>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nstruct WarshallFloyd {\r\n  std::vector<std::vector<T>> graph, dist;\r\
    \n\r\n  WarshallFloyd(const std::vector<std::vector<T>> &graph, const T TINF)\
    \ : graph(graph), dist(graph), TINF(TINF) {\r\n    n = graph.size();\r\n    internal.assign(n,\
    \ std::vector<int>(n, -1));\r\n    for (int k = 0; k < n; ++k) for (int i = 0;\
    \ i < n; ++i) for (int j = 0; j < n; ++j) {\r\n      if (dist[i][j] > dist[i][k]\
    \ + dist[k][j]) {\r\n        dist[i][j] = dist[i][k] + dist[k][j];\r\n       \
    \ internal[i][j] = k;\r\n      }\r\n    }\r\n  }\r\n\r\n  void add(int src, int\
    \ dst, T cost) {\r\n    srcs.emplace_back(src);\r\n    dsts.emplace_back(dst);\r\
    \n    costs.emplace_back(cost);\r\n  }\r\n\r\n  void calc() {\r\n    std::set<int>\
    \ vers;\r\n    int sz = srcs.size();\r\n    for (int i = 0; i < sz; ++i) {\r\n\
    \      int s = srcs[i], t = dsts[i];\r\n      T cost = costs[i];\r\n      if (cost\
    \ < graph[s][t]) graph[s][t] = cost;\r\n      if (dist[s][t] >= cost) {\r\n  \
    \      dist[s][t] = cost;\r\n        internal[s][t] = -1;\r\n      }\r\n     \
    \ vers.emplace(s);\r\n      vers.emplace(t);\r\n    }\r\n    for (int v : vers)\
    \ {\r\n      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {\r\n   \
    \     if (dist[i][j] > dist[i][v] + dist[v][j]) {\r\n          dist[i][j] = dist[i][v]\
    \ + dist[v][j];\r\n          internal[i][j] = v;\r\n        }\r\n      }\r\n \
    \   }\r\n    srcs.clear();\r\n    dsts.clear();\r\n    costs.clear();\r\n  }\r\
    \n\r\n  bool has_negative_cycle() const {\r\n    for (int i = 0; i < n; ++i) {\r\
    \n      if (dist[i][i] < 0) return true;\r\n    }\r\n    return false;\r\n  }\r\
    \n\r\n  std::vector<int> build_path(int s, int t) const {\r\n    std::vector<int>\
    \ res;\r\n    if (dist[s][t] != TINF) {\r\n      build_path(s, t, res);\r\n  \
    \    res.emplace_back(t);\r\n    }\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  const T TINF;\r\n  int n;\r\n  std::vector<std::vector<int>> internal;\r\n\
    \  std::vector<int> srcs, dsts;\r\n  std::vector<T> costs;\r\n\r\n  void build_path(int\
    \ s, int t, std::vector<int> &path) const {\r\n    int k = internal[s][t];\r\n\
    \    if (k == -1) {\r\n      path.emplace_back(s);\r\n    } else {\r\n      build_path(s,\
    \ k, path);\r\n      build_path(k, t, path);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/shortest_path/warshall-floyd.test.cpp
documentation_of: graph/shortest_path/warshall-floyd.hpp
layout: document
title: "Warshall-Floyd \u6CD5"
---

任意の2頂点間の最短路を求める全点対最短路問題を解くことができるアルゴリズムである．


## 時間計算量

$O({\lvert V \rvert}^3)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`WarshallFloyd<T>(graph, ∞)`|グラフ $graph$ の全点対最短路を考える．|隣接行列は $\infty$ で初期化しておかなければならない．|
|`graph[s][t]`|始点 $s$, 終点 $t$ を結ぶ辺のコストの最小値|存在しないならば $\infty$ となる．|
|`dist[s][t]`|始点 $s$ から終点 $t$ までの最短距離|到達不可能ならば $\infty$ となる．|
|`add(src, dst, cost)`|始点 $src$, 終点 $dst$, 重み $cost$ の辺をグラフに追加する．|
|`calc()`|辺をグラフに追加後, 全点対最短路を構築する．||
|`has_negative_cycle()`|グラフが負の閉路をもつか．||
|`build_path(s, t)`|始点 $s$ から終点 $t$ までの最短路||


## 参考

- http://www.prefield.com/algorithm/graph/floyd_warshall.html
- https://ei1333.github.io/luzhiled/snippets/graph/warshall-floyd.html


## ToDo

- Johnson's algorithm
  - http://www.prefield.com/algorithm/graph/johnson.html
  - https://inzkyk.github.io/algorithms/all_pairs_shortest_paths/johnsons_algorithm/


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0526/review/4082670/emthrm/C++14
