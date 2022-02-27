---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/warshall-floyd.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013Floyd\
      \ \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest_path/warshall-floyd.hpp\"\n#include <algorithm>\r\
    \n#include <iterator>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct\
    \ WarshallFloyd {\r\n  std::vector<std::vector<T>> graph, dist;\r\n\r\n  WarshallFloyd(const\
    \ std::vector<std::vector<T>>& graph, const T inf)\r\n      : graph(graph), dist(graph),\
    \ inf(inf), n(graph.size()),\r\n        internal(n, std::vector<int>(n, -1)) {\r\
    \n    for (int k = 0; k < n; ++k) {\r\n      for (int i = 0; i < n; ++i) {\r\n\
    \        for (int j = 0; j < n; ++j) {\r\n          if (dist[i][k] + dist[k][j]\
    \ < dist[i][j]) {\r\n            dist[i][j] = dist[i][k] + dist[k][j];\r\n   \
    \         internal[i][j] = k;\r\n          }\r\n        }\r\n      }\r\n    }\r\
    \n  }\r\n\r\n  void add(const int src, const int dst, const T cost) {\r\n    srcs.emplace_back(src);\r\
    \n    dsts.emplace_back(dst);\r\n    costs.emplace_back(cost);\r\n  }\r\n\r\n\
    \  void calc() {\r\n    const int m = srcs.size();\r\n    for (int i = 0; i <\
    \ m; ++i) {\r\n      graph[srcs[i]][dsts[i]] = std::min(graph[srcs[i]][dsts[i]],\
    \ costs[i]);\r\n      if (costs[i] <= dist[srcs[i]][dsts[i]]) {\r\n        dist[srcs[i]][dsts[i]]\
    \ = costs[i];\r\n        internal[srcs[i]][dsts[i]] = -1;\r\n      }\r\n    }\r\
    \n    std::vector<int> vers(m * 2);\r\n    std::copy(srcs.begin(), srcs.end(),\
    \ vers.begin());\r\n    std::copy(dsts.begin(), dsts.end(), std::next(vers.begin(),\
    \ m));\r\n    std::sort(vers.begin(), vers.end());\r\n    vers.erase(std::unique(vers.begin(),\
    \ vers.end()), vers.end());\r\n    for (const int ver : vers) {\r\n      for (int\
    \ i = 0; i < n; ++i) {\r\n        for (int j = 0; j < n; ++j) {\r\n          if\
    \ (dist[i][j] > dist[i][ver] + dist[ver][j]) {\r\n            dist[i][j] = dist[i][ver]\
    \ + dist[ver][j];\r\n            internal[i][j] = ver;\r\n          }\r\n    \
    \    }\r\n      }\r\n    }\r\n    srcs.clear();\r\n    dsts.clear();\r\n    costs.clear();\r\
    \n  }\r\n\r\n  bool has_negative_cycle() const {\r\n    for (int i = 0; i < n;\
    \ ++i) {\r\n      if (dist[i][i] < 0) return true;\r\n    }\r\n    return false;\r\
    \n  }\r\n\r\n  std::vector<int> build_path(const int s, const int t) const {\r\
    \n    std::vector<int> res;\r\n    if (dist[s][t] != inf) {\r\n      build_path(s,\
    \ t, &res);\r\n      res.emplace_back(t);\r\n    }\r\n    return res;\r\n  }\r\
    \n\r\n private:\r\n  const T inf;\r\n  const int n;\r\n  std::vector<int> srcs,\
    \ dsts;\r\n  std::vector<T> costs;\r\n  std::vector<std::vector<int>> internal;\r\
    \n\r\n  void build_path(const int s, const int t, std::vector<int>* path) const\
    \ {\r\n    const int k = internal[s][t];\r\n    if (k == -1) {\r\n      (*path).emplace_back(s);\r\
    \n    } else {\r\n      build_path(s, k, path);\r\n      build_path(k, t, path);\r\
    \n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <iterator>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstruct WarshallFloyd {\r\n  std::vector<std::vector<T>>\
    \ graph, dist;\r\n\r\n  WarshallFloyd(const std::vector<std::vector<T>>& graph,\
    \ const T inf)\r\n      : graph(graph), dist(graph), inf(inf), n(graph.size()),\r\
    \n        internal(n, std::vector<int>(n, -1)) {\r\n    for (int k = 0; k < n;\
    \ ++k) {\r\n      for (int i = 0; i < n; ++i) {\r\n        for (int j = 0; j <\
    \ n; ++j) {\r\n          if (dist[i][k] + dist[k][j] < dist[i][j]) {\r\n     \
    \       dist[i][j] = dist[i][k] + dist[k][j];\r\n            internal[i][j] =\
    \ k;\r\n          }\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  void add(const\
    \ int src, const int dst, const T cost) {\r\n    srcs.emplace_back(src);\r\n \
    \   dsts.emplace_back(dst);\r\n    costs.emplace_back(cost);\r\n  }\r\n\r\n  void\
    \ calc() {\r\n    const int m = srcs.size();\r\n    for (int i = 0; i < m; ++i)\
    \ {\r\n      graph[srcs[i]][dsts[i]] = std::min(graph[srcs[i]][dsts[i]], costs[i]);\r\
    \n      if (costs[i] <= dist[srcs[i]][dsts[i]]) {\r\n        dist[srcs[i]][dsts[i]]\
    \ = costs[i];\r\n        internal[srcs[i]][dsts[i]] = -1;\r\n      }\r\n    }\r\
    \n    std::vector<int> vers(m * 2);\r\n    std::copy(srcs.begin(), srcs.end(),\
    \ vers.begin());\r\n    std::copy(dsts.begin(), dsts.end(), std::next(vers.begin(),\
    \ m));\r\n    std::sort(vers.begin(), vers.end());\r\n    vers.erase(std::unique(vers.begin(),\
    \ vers.end()), vers.end());\r\n    for (const int ver : vers) {\r\n      for (int\
    \ i = 0; i < n; ++i) {\r\n        for (int j = 0; j < n; ++j) {\r\n          if\
    \ (dist[i][j] > dist[i][ver] + dist[ver][j]) {\r\n            dist[i][j] = dist[i][ver]\
    \ + dist[ver][j];\r\n            internal[i][j] = ver;\r\n          }\r\n    \
    \    }\r\n      }\r\n    }\r\n    srcs.clear();\r\n    dsts.clear();\r\n    costs.clear();\r\
    \n  }\r\n\r\n  bool has_negative_cycle() const {\r\n    for (int i = 0; i < n;\
    \ ++i) {\r\n      if (dist[i][i] < 0) return true;\r\n    }\r\n    return false;\r\
    \n  }\r\n\r\n  std::vector<int> build_path(const int s, const int t) const {\r\
    \n    std::vector<int> res;\r\n    if (dist[s][t] != inf) {\r\n      build_path(s,\
    \ t, &res);\r\n      res.emplace_back(t);\r\n    }\r\n    return res;\r\n  }\r\
    \n\r\n private:\r\n  const T inf;\r\n  const int n;\r\n  std::vector<int> srcs,\
    \ dsts;\r\n  std::vector<T> costs;\r\n  std::vector<std::vector<int>> internal;\r\
    \n\r\n  void build_path(const int s, const int t, std::vector<int>* path) const\
    \ {\r\n    const int k = internal[s][t];\r\n    if (k == -1) {\r\n      (*path).emplace_back(s);\r\
    \n    } else {\r\n      build_path(s, k, path);\r\n      build_path(k, t, path);\r\
    \n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/shortest_path/warshall-floyd.test.cpp
documentation_of: graph/shortest_path/warshall-floyd.hpp
layout: document
title: "Warshall\u2013Floyd \u6CD5"
---

任意の2頂点間の最短路を求める全点対最短路問題を解けるアルゴリズムである．


## 時間計算量

$O({\lvert V \rvert}^3)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`WarshallFloyd<T>(graph, ∞)`|グラフ $\mathrm{graph}$ の全点対最短路を考える．|隣接行列は $\infty$ で初期化しておかなければならない．|
|`graph[s][t]`|始点 $s$, 終点 $t$ を結ぶ辺の最小コスト|存在しなければ $\infty$ となる．|
|`dist[s][t]`|始点 $s$ から終点 $t$ までの最短距離|到達できなければ $\infty$ となる．|
|`add(src, dst, cost)`|始点 $\mathrm{src}$，終点 $\mathrm{dst}$，重み $\mathrm{cost}$ の辺をグラフに加える．|
|`calc()`|辺をグラフに追加した後, 全点対最短路を構築する．||
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
