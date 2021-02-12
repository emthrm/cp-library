---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u71C3\u3084\u3059\
      \u57CB\u3081\u308B"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/flow/maximum_flow/project_selection_problem.hpp\"\n\
    #include <cassert>\r\n#include <limits>\r\n#include <vector>\r\n\r\ntemplate <template\
    \ <typename> class C, typename T>\r\nstruct ProjectSelectionProblem {\r\n  ProjectSelectionProblem(int\
    \ n) : n(n) {}\r\n\r\n  void add_diff(int u, int v, T cost) {\r\n    assert(cost\
    \ >= 0);\r\n    diff_u.emplace_back(u);\r\n    diff_v.emplace_back(v);\r\n   \
    \ diff_cost.emplace_back(cost);\r\n  }\r\n\r\n  void add_same(int u, int v, int\
    \ group, T cost) {\r\n    assert(cost <= 0);\r\n    cost = -cost;\r\n    res +=\
    \ cost;\r\n    add(n, group ^ 1, cost);\r\n    if (group == 0) {\r\n      add_diff(n,\
    \ u, inf);\r\n      add_diff(n, v, inf);\r\n    } else if (group == 1) {\r\n \
    \     add_diff(u, n, inf);\r\n      add_diff(v, n, inf);\r\n    }\r\n    ++n;\r\
    \n  }\r\n\r\n  void add(int ver, int group, T cost) {\r\n    if (cost < 0) {\r\
    \n      cost = -cost;\r\n      res += cost;\r\n      add(ver, group ^ 1, cost);\r\
    \n    } else {\r\n      if (group == 0) {\r\n        add_diff(ver, -1, cost);\r\
    \n      } else {\r\n        add_diff(-2, ver, cost);\r\n      }\r\n    }\r\n \
    \ }\r\n\r\n  T solve() {\r\n    C<T> flow(n + 2);\r\n    int diff_sz = diff_u.size();\r\
    \n    for (int i = 0; i < diff_sz; ++i) {\r\n      if (diff_u[i] < 0) diff_u[i]\
    \ += n + 2;\r\n      if (diff_v[i] < 0) diff_v[i] += n + 2;\r\n      flow.add_edge(diff_u[i],\
    \ diff_v[i], diff_cost[i]);\r\n    }\r\n    int same_sz = same_u.size();\r\n \
    \   for (int i = 0; i < same_sz; ++i) {\r\n      if (same_u[i] < 0) same_u[i]\
    \ += n + 2;\r\n      if (same_v[i] < 0) same_v[i] += n + 2;\r\n      flow.add_edge(same_u[i],\
    \ same_v[i], same_cost[i]);\r\n    }\r\n    return flow.maximum_flow(n, n + 1,\
    \ inf) - res;\r\n  }\r\n\r\nprivate:\r\n  int n;\r\n  const T inf = std::numeric_limits<T>::max();\r\
    \n  T res = 0;\r\n  std::vector<int> diff_u, diff_v, same_u, same_v;\r\n  std::vector<T>\
    \ diff_cost, same_cost;\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <limits>\r\n#include <vector>\r\
    \n\r\ntemplate <template <typename> class C, typename T>\r\nstruct ProjectSelectionProblem\
    \ {\r\n  ProjectSelectionProblem(int n) : n(n) {}\r\n\r\n  void add_diff(int u,\
    \ int v, T cost) {\r\n    assert(cost >= 0);\r\n    diff_u.emplace_back(u);\r\n\
    \    diff_v.emplace_back(v);\r\n    diff_cost.emplace_back(cost);\r\n  }\r\n\r\
    \n  void add_same(int u, int v, int group, T cost) {\r\n    assert(cost <= 0);\r\
    \n    cost = -cost;\r\n    res += cost;\r\n    add(n, group ^ 1, cost);\r\n  \
    \  if (group == 0) {\r\n      add_diff(n, u, inf);\r\n      add_diff(n, v, inf);\r\
    \n    } else if (group == 1) {\r\n      add_diff(u, n, inf);\r\n      add_diff(v,\
    \ n, inf);\r\n    }\r\n    ++n;\r\n  }\r\n\r\n  void add(int ver, int group, T\
    \ cost) {\r\n    if (cost < 0) {\r\n      cost = -cost;\r\n      res += cost;\r\
    \n      add(ver, group ^ 1, cost);\r\n    } else {\r\n      if (group == 0) {\r\
    \n        add_diff(ver, -1, cost);\r\n      } else {\r\n        add_diff(-2, ver,\
    \ cost);\r\n      }\r\n    }\r\n  }\r\n\r\n  T solve() {\r\n    C<T> flow(n +\
    \ 2);\r\n    int diff_sz = diff_u.size();\r\n    for (int i = 0; i < diff_sz;\
    \ ++i) {\r\n      if (diff_u[i] < 0) diff_u[i] += n + 2;\r\n      if (diff_v[i]\
    \ < 0) diff_v[i] += n + 2;\r\n      flow.add_edge(diff_u[i], diff_v[i], diff_cost[i]);\r\
    \n    }\r\n    int same_sz = same_u.size();\r\n    for (int i = 0; i < same_sz;\
    \ ++i) {\r\n      if (same_u[i] < 0) same_u[i] += n + 2;\r\n      if (same_v[i]\
    \ < 0) same_v[i] += n + 2;\r\n      flow.add_edge(same_u[i], same_v[i], same_cost[i]);\r\
    \n    }\r\n    return flow.maximum_flow(n, n + 1, inf) - res;\r\n  }\r\n\r\nprivate:\r\
    \n  int n;\r\n  const T inf = std::numeric_limits<T>::max();\r\n  T res = 0;\r\
    \n  std::vector<int> diff_u, diff_v, same_u, same_v;\r\n  std::vector<T> diff_cost,\
    \ same_cost;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/maximum_flow/project_selection_problem.hpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/project_selection_problem.test.cpp
documentation_of: graph/flow/maximum_flow/project_selection_problem.hpp
layout: document
title: "\u71C3\u3084\u3059\u57CB\u3081\u308B (project selection problem)"
---

厳密には「燃やす埋める」と "Project Selection Problem" は異なる．


## 計算量

[最大流](maximum_flow.md)に同じ．


## 使用法

||説明|
|:--:|:--:|
|`ProjectSelectionProblem<最大流, T>(n)`|頂点数 $N$ の燃やす埋めるを考える．|
|`add_diff(u, v, cost)`|$u$ が集合 $0$, $v$ が集合 $1$ に属するならばコスト $\mathrm{cost}(\geq 0)$ を消費すると定義する．|
|`add_same(u, v, group, cost)`|$u$ と $v$ がともに集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost}(\leq 0)$ を消費すると定義する．|
|`add(ver, group, cost)`|$\mathrm{ver}$ が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost}$ を消費すると定義する．|
|`solve()`|最小コスト|


## 参考

- https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
- https://ei1333.github.io/algorithm/dinic.html


## ToDo

- https://koyumeishi.hatenablog.com/entry/2021/01/14/052223


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2903/review/4099641/emthrm/C++14
