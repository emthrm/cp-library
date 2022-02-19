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
  bundledCode: "#line 2 \"misc/2-sat.hpp\"\n#include <algorithm>\r\n#include <vector>\r\
    \n\r\nstruct TwoSat {\r\n  explicit TwoSat(const int n)\r\n      : n(n), graph(n\
    \ << 1), rgraph(n << 1), is_visited(n << 1), ids(n << 1) {\r\n    order.reserve(n\
    \ << 1);\r\n  }\r\n\r\n  int negate(const int x) const { return (n + x) % (n <<\
    \ 1); }\r\n\r\n  void add_or(const int x, const int y) {\r\n    graph[negate(x)].emplace_back(y);\r\
    \n    graph[negate(y)].emplace_back(x);\r\n    rgraph[y].emplace_back(negate(x));\r\
    \n    rgraph[x].emplace_back(negate(y));\r\n  }\r\n\r\n  void add_if(const int\
    \ x, const int y) { add_or(negate(x), y); }\r\n\r\n  void add_nand(const int x,\
    \ const int y) { add_or(negate(x), negate(y)); }\r\n\r\n  void set_true(const\
    \ int x) { add_or(x, x); }\r\n\r\n  void set_false(const int x) { set_true(negate(x));\
    \ }\r\n\r\n  std::vector<bool> build() {\r\n    std::fill(is_visited.begin(),\
    \ is_visited.end(), false);\r\n    std::fill(ids.begin(), ids.end(), -1);\r\n\
    \    order.clear();\r\n    for (int i = 0; i < (n << 1); ++i) {\r\n      if (!is_visited[i])\
    \ dfs(i);\r\n    }\r\n    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {\r\n\
    \      if (ids[order[i]] == -1) rdfs(order[i], id++);\r\n    }\r\n    std::vector<bool>\
    \ res(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (ids[i] == ids[negate(i)])\
    \ return {};\r\n      res[i] = ids[negate(i)] < ids[i];\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n private:\r\n  const int n;\r\n  std::vector<std::vector<int>>\
    \ graph, rgraph;\r\n  std::vector<bool> is_visited;\r\n  std::vector<int> ids,\
    \ order;\r\n\r\n  void dfs(const int ver) {\r\n    is_visited[ver] = true;\r\n\
    \    for (const int dst : graph[ver]) {\r\n      if (!is_visited[dst]) dfs(dst);\r\
    \n    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n  void rdfs(const int ver,\
    \ const int cur_id) {\r\n    ids[ver] = cur_id;\r\n    for (const int dst : rgraph[ver])\
    \ {\r\n      if (ids[dst] == -1) rdfs(dst, cur_id);\r\n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\nstruct TwoSat\
    \ {\r\n  explicit TwoSat(const int n)\r\n      : n(n), graph(n << 1), rgraph(n\
    \ << 1), is_visited(n << 1), ids(n << 1) {\r\n    order.reserve(n << 1);\r\n \
    \ }\r\n\r\n  int negate(const int x) const { return (n + x) % (n << 1); }\r\n\r\
    \n  void add_or(const int x, const int y) {\r\n    graph[negate(x)].emplace_back(y);\r\
    \n    graph[negate(y)].emplace_back(x);\r\n    rgraph[y].emplace_back(negate(x));\r\
    \n    rgraph[x].emplace_back(negate(y));\r\n  }\r\n\r\n  void add_if(const int\
    \ x, const int y) { add_or(negate(x), y); }\r\n\r\n  void add_nand(const int x,\
    \ const int y) { add_or(negate(x), negate(y)); }\r\n\r\n  void set_true(const\
    \ int x) { add_or(x, x); }\r\n\r\n  void set_false(const int x) { set_true(negate(x));\
    \ }\r\n\r\n  std::vector<bool> build() {\r\n    std::fill(is_visited.begin(),\
    \ is_visited.end(), false);\r\n    std::fill(ids.begin(), ids.end(), -1);\r\n\
    \    order.clear();\r\n    for (int i = 0; i < (n << 1); ++i) {\r\n      if (!is_visited[i])\
    \ dfs(i);\r\n    }\r\n    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {\r\n\
    \      if (ids[order[i]] == -1) rdfs(order[i], id++);\r\n    }\r\n    std::vector<bool>\
    \ res(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (ids[i] == ids[negate(i)])\
    \ return {};\r\n      res[i] = ids[negate(i)] < ids[i];\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n private:\r\n  const int n;\r\n  std::vector<std::vector<int>>\
    \ graph, rgraph;\r\n  std::vector<bool> is_visited;\r\n  std::vector<int> ids,\
    \ order;\r\n\r\n  void dfs(const int ver) {\r\n    is_visited[ver] = true;\r\n\
    \    for (const int dst : graph[ver]) {\r\n      if (!is_visited[dst]) dfs(dst);\r\
    \n    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n  void rdfs(const int ver,\
    \ const int cur_id) {\r\n    ids[ver] = cur_id;\r\n    for (const int dst : rgraph[ver])\
    \ {\r\n      if (ids[dst] == -1) rdfs(dst, cur_id);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/2-sat.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/2-sat.test.cpp
documentation_of: misc/2-sat.hpp
layout: document
title: 2-SAT
---

節内のリテラル数が高々 $2$ である連言標準形の充足可能性を判定する問題である．


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
|`set_true(x)`|$x$ を真とする．||
|`set_false(x)`|$x$ を偽とする．||
|`build()`|変数の真理値|矛盾が生じるときは空配列となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.288-290，マイナビ出版（2012）
- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp


## Verified

- https://judge.yosupo.jp/submission/2711
