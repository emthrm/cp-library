---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/shortest_path/warshall-floyd.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013Floyd\
      \ \u6CD5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/shortest_path/warshall-floyd.hpp\"\n\
    \n\n\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nstruct WarshallFloyd {\n  std::vector<std::vector<T>>\
    \ graph, dist;\n\n  WarshallFloyd(const std::vector<std::vector<T>>& graph, const\
    \ T inf)\n      : graph(graph), dist(graph), inf(inf), n(graph.size()),\n    \
    \    internal(n, std::vector<int>(n, -1)) {\n    for (int k = 0; k < n; ++k) {\n\
    \      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < n; ++j) {\n\
    \          if (dist[i][k] + dist[k][j] < dist[i][j]) {\n            dist[i][j]\
    \ = dist[i][k] + dist[k][j];\n            internal[i][j] = k;\n          }\n \
    \       }\n      }\n    }\n  }\n\n  void add(const int src, const int dst, const\
    \ T cost) {\n    srcs.emplace_back(src);\n    dsts.emplace_back(dst);\n    costs.emplace_back(cost);\n\
    \  }\n\n  void calc() {\n    const int m = srcs.size();\n    for (int i = 0; i\
    \ < m; ++i) {\n      graph[srcs[i]][dsts[i]] = std::min(graph[srcs[i]][dsts[i]],\
    \ costs[i]);\n      if (costs[i] <= dist[srcs[i]][dsts[i]]) {\n        dist[srcs[i]][dsts[i]]\
    \ = costs[i];\n        internal[srcs[i]][dsts[i]] = -1;\n      }\n    }\n    std::vector<int>\
    \ vers(m * 2);\n    std::copy(srcs.begin(), srcs.end(), vers.begin());\n    std::copy(dsts.begin(),\
    \ dsts.end(), std::next(vers.begin(), m));\n    std::sort(vers.begin(), vers.end());\n\
    \    vers.erase(std::unique(vers.begin(), vers.end()), vers.end());\n    for (const\
    \ int ver : vers) {\n      for (int i = 0; i < n; ++i) {\n        for (int j =\
    \ 0; j < n; ++j) {\n          if (dist[i][j] > dist[i][ver] + dist[ver][j]) {\n\
    \            dist[i][j] = dist[i][ver] + dist[ver][j];\n            internal[i][j]\
    \ = ver;\n          }\n        }\n      }\n    }\n    srcs.clear();\n    dsts.clear();\n\
    \    costs.clear();\n  }\n\n  bool has_negative_cycle() const {\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (dist[i][i] < 0) return true;\n    }\n    return\
    \ false;\n  }\n\n  std::vector<int> build_path(const int s, const int t) const\
    \ {\n    std::vector<int> res;\n    if (dist[s][t] != inf) {\n      build_path(s,\
    \ t, &res);\n      res.emplace_back(t);\n    }\n    return res;\n  }\n\n private:\n\
    \  const T inf;\n  const int n;\n  std::vector<int> srcs, dsts;\n  std::vector<T>\
    \ costs;\n  std::vector<std::vector<int>> internal;\n\n  void build_path(const\
    \ int s, const int t, std::vector<int>* path) const {\n    const int k = internal[s][t];\n\
    \    if (k == -1) {\n      (*path).emplace_back(s);\n    } else {\n      build_path(s,\
    \ k, path);\n      build_path(k, t, path);\n    }\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_SHORTEST_PATH_WARSHALL_FLOYD_HPP_\n#define EMTHRM_GRAPH_SHORTEST_PATH_WARSHALL_FLOYD_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstruct WarshallFloyd {\n  std::vector<std::vector<T>>\
    \ graph, dist;\n\n  WarshallFloyd(const std::vector<std::vector<T>>& graph, const\
    \ T inf)\n      : graph(graph), dist(graph), inf(inf), n(graph.size()),\n    \
    \    internal(n, std::vector<int>(n, -1)) {\n    for (int k = 0; k < n; ++k) {\n\
    \      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < n; ++j) {\n\
    \          if (dist[i][k] + dist[k][j] < dist[i][j]) {\n            dist[i][j]\
    \ = dist[i][k] + dist[k][j];\n            internal[i][j] = k;\n          }\n \
    \       }\n      }\n    }\n  }\n\n  void add(const int src, const int dst, const\
    \ T cost) {\n    srcs.emplace_back(src);\n    dsts.emplace_back(dst);\n    costs.emplace_back(cost);\n\
    \  }\n\n  void calc() {\n    const int m = srcs.size();\n    for (int i = 0; i\
    \ < m; ++i) {\n      graph[srcs[i]][dsts[i]] = std::min(graph[srcs[i]][dsts[i]],\
    \ costs[i]);\n      if (costs[i] <= dist[srcs[i]][dsts[i]]) {\n        dist[srcs[i]][dsts[i]]\
    \ = costs[i];\n        internal[srcs[i]][dsts[i]] = -1;\n      }\n    }\n    std::vector<int>\
    \ vers(m * 2);\n    std::copy(srcs.begin(), srcs.end(), vers.begin());\n    std::copy(dsts.begin(),\
    \ dsts.end(), std::next(vers.begin(), m));\n    std::sort(vers.begin(), vers.end());\n\
    \    vers.erase(std::unique(vers.begin(), vers.end()), vers.end());\n    for (const\
    \ int ver : vers) {\n      for (int i = 0; i < n; ++i) {\n        for (int j =\
    \ 0; j < n; ++j) {\n          if (dist[i][j] > dist[i][ver] + dist[ver][j]) {\n\
    \            dist[i][j] = dist[i][ver] + dist[ver][j];\n            internal[i][j]\
    \ = ver;\n          }\n        }\n      }\n    }\n    srcs.clear();\n    dsts.clear();\n\
    \    costs.clear();\n  }\n\n  bool has_negative_cycle() const {\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (dist[i][i] < 0) return true;\n    }\n    return\
    \ false;\n  }\n\n  std::vector<int> build_path(const int s, const int t) const\
    \ {\n    std::vector<int> res;\n    if (dist[s][t] != inf) {\n      build_path(s,\
    \ t, &res);\n      res.emplace_back(t);\n    }\n    return res;\n  }\n\n private:\n\
    \  const T inf;\n  const int n;\n  std::vector<int> srcs, dsts;\n  std::vector<T>\
    \ costs;\n  std::vector<std::vector<int>> internal;\n\n  void build_path(const\
    \ int s, const int t, std::vector<int>* path) const {\n    const int k = internal[s][t];\n\
    \    if (k == -1) {\n      (*path).emplace_back(s);\n    } else {\n      build_path(s,\
    \ k, path);\n      build_path(k, t, path);\n    }\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_SHORTEST_PATH_WARSHALL_FLOYD_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/graph/shortest_path/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/shortest_path/warshall-floyd.test.cpp
documentation_of: include/emthrm/graph/shortest_path/warshall-floyd.hpp
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


## TODO

- Johnson's algorithm
  - http://www.prefield.com/algorithm/graph/johnson.html
  - https://inzkyk.github.io/algorithms/all_pairs_shortest_paths/johnsons_algorithm/


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0526/review/4082670/emthrm/C++14
