---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/project selection\
      \ problem"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/flow/maximum_flow/project_selection_problem.hpp\"\n\
    #include <cassert>\r\n#include <limits>\r\n#include <vector>\r\n\r\ntemplate <template\
    \ <typename> class C, typename T>\r\nstruct ProjectSelectionProblem {\r\n  ProjectSelectionProblem(int\
    \ n) : n(n) {}\r\n\r\n  void add_neq(int u, int v, T cost) {\r\n    assert(cost\
    \ >= 0);\r\n    us.emplace_back(u);\r\n    vs.emplace_back(v);\r\n    costs.emplace_back(cost);\r\
    \n  }\r\n\r\n  void add(int v, bool group, T cost) {\r\n    if (cost < 0) {\r\n\
    \      cost = -cost;\r\n      res += cost;\r\n      group = !group;\r\n    }\r\
    \n    if (group) {\r\n      add_neq(-2, v, cost);  // -2 represents S.\r\n   \
    \ } else {\r\n      add_neq(v, -1, cost);  // -1 represents T.\r\n    }\r\n  }\r\
    \n\r\n  void add_or(const std::vector<int> &v, bool group, T cost) {\r\n    assert(cost\
    \ >= 0);\r\n    add(n, group, cost);\r\n    if (group) {\r\n      for (int vi\
    \ : v) add_neq(n, vi, inf);\r\n    } else {\r\n      for (int vi : v) add_neq(vi,\
    \ n, inf);\r\n    }\r\n    ++n;\r\n  }\r\n\r\n  void add_or(int u, int v, bool\
    \ group, T cost) { add_or({u, v}, group, cost); }\r\n\r\n  void add_eq(const std::vector<int>\
    \ &v, bool group, T cost) {\r\n    assert(cost <= 0);\r\n    cost = -cost;\r\n\
    \    res += cost;\r\n    add_or(v, !group, cost);\r\n  }\r\n\r\n  void add_eq(int\
    \ u, int v, bool group, T cost) { add_eq({u, v}, group, cost); }\r\n\r\n  T solve()\
    \ {\r\n    C<T> flow(n + 2);\r\n    int neq_sz = costs.size();\r\n    for (int\
    \ i = 0; i < neq_sz; ++i) {\r\n      flow.add_edge(us[i] < 0 ? us[i] + n + 2 :\
    \ us[i], vs[i] < 0 ? vs[i] + n + 2 : vs[i], costs[i]);\r\n    }\r\n    return\
    \ flow.maximum_flow(n, n + 1, inf) - res;\r\n  }\r\n\r\nprivate:\r\n  const T\
    \ inf = std::numeric_limits<T>::max();\r\n  int n;\r\n  T res = 0;\r\n  std::vector<int>\
    \ us, vs;\r\n  std::vector<T> costs;\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <limits>\r\n#include <vector>\r\
    \n\r\ntemplate <template <typename> class C, typename T>\r\nstruct ProjectSelectionProblem\
    \ {\r\n  ProjectSelectionProblem(int n) : n(n) {}\r\n\r\n  void add_neq(int u,\
    \ int v, T cost) {\r\n    assert(cost >= 0);\r\n    us.emplace_back(u);\r\n  \
    \  vs.emplace_back(v);\r\n    costs.emplace_back(cost);\r\n  }\r\n\r\n  void add(int\
    \ v, bool group, T cost) {\r\n    if (cost < 0) {\r\n      cost = -cost;\r\n \
    \     res += cost;\r\n      group = !group;\r\n    }\r\n    if (group) {\r\n \
    \     add_neq(-2, v, cost);  // -2 represents S.\r\n    } else {\r\n      add_neq(v,\
    \ -1, cost);  // -1 represents T.\r\n    }\r\n  }\r\n\r\n  void add_or(const std::vector<int>\
    \ &v, bool group, T cost) {\r\n    assert(cost >= 0);\r\n    add(n, group, cost);\r\
    \n    if (group) {\r\n      for (int vi : v) add_neq(n, vi, inf);\r\n    } else\
    \ {\r\n      for (int vi : v) add_neq(vi, n, inf);\r\n    }\r\n    ++n;\r\n  }\r\
    \n\r\n  void add_or(int u, int v, bool group, T cost) { add_or({u, v}, group,\
    \ cost); }\r\n\r\n  void add_eq(const std::vector<int> &v, bool group, T cost)\
    \ {\r\n    assert(cost <= 0);\r\n    cost = -cost;\r\n    res += cost;\r\n   \
    \ add_or(v, !group, cost);\r\n  }\r\n\r\n  void add_eq(int u, int v, bool group,\
    \ T cost) { add_eq({u, v}, group, cost); }\r\n\r\n  T solve() {\r\n    C<T> flow(n\
    \ + 2);\r\n    int neq_sz = costs.size();\r\n    for (int i = 0; i < neq_sz; ++i)\
    \ {\r\n      flow.add_edge(us[i] < 0 ? us[i] + n + 2 : us[i], vs[i] < 0 ? vs[i]\
    \ + n + 2 : vs[i], costs[i]);\r\n    }\r\n    return flow.maximum_flow(n, n +\
    \ 1, inf) - res;\r\n  }\r\n\r\nprivate:\r\n  const T inf = std::numeric_limits<T>::max();\r\
    \n  int n;\r\n  T res = 0;\r\n  std::vector<int> us, vs;\r\n  std::vector<T> costs;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/maximum_flow/project_selection_problem.hpp
  requiredBy: []
  timestamp: '2021-03-15 19:56:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/project_selection_problem.test.cpp
documentation_of: graph/flow/maximum_flow/project_selection_problem.hpp
layout: document
title: project selection problem
---


## 計算量

[最大流](maximum_flow.md)に同じ．


## 使用法

||説明|
|:--:|:--:|
|`ProjectSelectionProblem<最大流, T>(n)`|頂点数 $N$ の project selection problem を考える．|
|`add_neq(u, v, cost)`|$u$ が集合 $0$, $v$ が集合 $1$ に属するならばコスト $\mathrm{cost} \ (\geq 0)$ かかると定義する．|
|`add(v, group, cost)`|$v$ が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost}$ かかると定義する．|
|`add_or(v, group, cost)`|集合 $\mathrm{group}$ に属する頂点 $v \in V$ が存在するならばコスト $\mathrm{cost} \ (\geq 0)$ かかると定義する．|
|`add_or(u, v, group, cost)`|$u, v$ のいずれかまたは両方が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \ (\geq 0)$ かかると定義する．|
|`add_eq(v, group, cost)`|$V$ に含まれる頂点すべてが集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \ (\leq 0)$ かかると定義する．|
|`add_eq(u, v, group, cost)`|$u, v$ 両方が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \ (\leq 0)$ かかると定義する．|
|`solve()`|最小費用|


## 参考

- https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
- https://ei1333.github.io/algorithm/dinic.html
- https://koyumeishi.hatenablog.com/entry/2021/01/14/052223


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2903/review/5292569/emthrm/C++17
