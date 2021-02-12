---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/2-sat.test.cpp
    title: "\u305D\u306E\u4ED6/2-SAT"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/2-sat.hpp\"\n#include <vector>\r\n\r\nstruct TwoSat\
    \ {\r\n  TwoSat(int n) : n(n), graph(n << 1), rev_graph(n << 1) {}\r\n\r\n  int\
    \ negate(int x) const { return (n + x) % (n << 1); }\r\n\r\n  void add_or(int\
    \ x, int y) {\r\n    graph[negate(x)].emplace_back(y);\r\n    graph[negate(y)].emplace_back(x);\r\
    \n    rev_graph[y].emplace_back(negate(x));\r\n    rev_graph[x].emplace_back(negate(y));\r\
    \n  }\r\n\r\n  void add_if(int x, int y) { add_or(negate(x), y); }\r\n\r\n  void\
    \ add_nand(int x, int y) { add_or(negate(x), negate(y)); }\r\n\r\n  void set_true(int\
    \ x) { add_or(x, x); }\r\n\r\n  void set_false(int x) { set_true(negate(x)); }\r\
    \n\r\n  std::vector<bool> build() {\r\n    used.assign(n << 1, false);\r\n   \
    \ id.assign(n << 1, -1);\r\n    order.clear();\r\n    for (int i = 0; i < (n <<\
    \ 1); ++i) {\r\n      if (!used[i]) dfs(i);\r\n    }\r\n    int now = 0;\r\n \
    \   for (int i = (n << 1) - 1; i >= 0; --i) {\r\n      if (id[order[i]] == -1)\
    \ rev_dfs(order[i], now++);\r\n    }\r\n    std::vector<bool> res(n);\r\n    for\
    \ (int i = 0; i < n; ++i) {\r\n      if (id[i] == id[negate(i)]) return {};\r\n\
    \      res[i] = id[negate(i)] < id[i];\r\n    }\r\n    return res;\r\n  }\r\n\r\
    \nprivate:\r\n  int n;\r\n  std::vector<std::vector<int>> graph, rev_graph;\r\n\
    \  std::vector<bool> used;\r\n  std::vector<int> id, order;\r\n\r\n  void dfs(int\
    \ ver) {\r\n    used[ver] = true;\r\n    for (int e : graph[ver]) {\r\n      if\
    \ (!used[e]) dfs(e);\r\n    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n \
    \ void rev_dfs(int ver, int now) {\r\n    id[ver] = now;\r\n    for (int e : rev_graph[ver])\
    \ {\r\n      if (id[e] == -1) rev_dfs(e, now);\r\n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\nstruct TwoSat {\r\n  TwoSat(int\
    \ n) : n(n), graph(n << 1), rev_graph(n << 1) {}\r\n\r\n  int negate(int x) const\
    \ { return (n + x) % (n << 1); }\r\n\r\n  void add_or(int x, int y) {\r\n    graph[negate(x)].emplace_back(y);\r\
    \n    graph[negate(y)].emplace_back(x);\r\n    rev_graph[y].emplace_back(negate(x));\r\
    \n    rev_graph[x].emplace_back(negate(y));\r\n  }\r\n\r\n  void add_if(int x,\
    \ int y) { add_or(negate(x), y); }\r\n\r\n  void add_nand(int x, int y) { add_or(negate(x),\
    \ negate(y)); }\r\n\r\n  void set_true(int x) { add_or(x, x); }\r\n\r\n  void\
    \ set_false(int x) { set_true(negate(x)); }\r\n\r\n  std::vector<bool> build()\
    \ {\r\n    used.assign(n << 1, false);\r\n    id.assign(n << 1, -1);\r\n    order.clear();\r\
    \n    for (int i = 0; i < (n << 1); ++i) {\r\n      if (!used[i]) dfs(i);\r\n\
    \    }\r\n    int now = 0;\r\n    for (int i = (n << 1) - 1; i >= 0; --i) {\r\n\
    \      if (id[order[i]] == -1) rev_dfs(order[i], now++);\r\n    }\r\n    std::vector<bool>\
    \ res(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (id[i] == id[negate(i)])\
    \ return {};\r\n      res[i] = id[negate(i)] < id[i];\r\n    }\r\n    return res;\r\
    \n  }\r\n\r\nprivate:\r\n  int n;\r\n  std::vector<std::vector<int>> graph, rev_graph;\r\
    \n  std::vector<bool> used;\r\n  std::vector<int> id, order;\r\n\r\n  void dfs(int\
    \ ver) {\r\n    used[ver] = true;\r\n    for (int e : graph[ver]) {\r\n      if\
    \ (!used[e]) dfs(e);\r\n    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n \
    \ void rev_dfs(int ver, int now) {\r\n    id[ver] = now;\r\n    for (int e : rev_graph[ver])\
    \ {\r\n      if (id[e] == -1) rev_dfs(e, now);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/2-sat.hpp
  requiredBy: []
  timestamp: '2021-02-12 21:17:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/2-sat.test.cpp
documentation_of: misc/2-sat.hpp
layout: document
title: 2-SAT
---

節内のリテラル数が高々2である連言標準形の充足可能性を判定する問題である．


## 時間計算量

$N$ 変数 $M$ 節 のとき $O(N + M)$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`TwoSat(n)`|$N$ 変数の 2-SAT を考える．||
|`negate(x)`|$\neg x$ を表す頂点番号||
|`add_or(x, y)`|$x \vee y$ を追加する．||
|`add_if(x, y)`|$x \Rightarrow y$ を追加する．||
|`add_nand(x, y)`|$\neg (x \land y)$ を追加する．||
|`set_true(x)`|$x$ を $T$ とする．||
|`set_false(x)`|$x$ を $F$ とする．||
|`build()`|各変数の真理値|矛盾が生じる場合は空配列となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.288-290
- https://github.com/beet-aizu/library/blob/master/graph/stronglyconnectedcomponent.cpp


## Verified

- https://judge.yosupo.jp/submission/2711
