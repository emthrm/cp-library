---
title: 燃やす埋める (project selection problem)
documentation_of: graph/flow/maximum_flow/project_selection_problem.hpp
---

厳密には「燃やす埋める」と "Project Selection Problem" は異なる．


## 計算量

[最大流](maximum_flow.md)に同じ．


## 使用法

||説明|
|:--:|:--:|
|`ProjectSelectionProblem<最大流, T>(n, ∞)`|頂点数 $N$ の燃やす埋めるを考える．|
|`add_diff(u, v, cost)`|$u$ が集合 $0$, $v$ が集合 $1$ に属するならばコスト $\mathrm{cost}(\geq 0)$ を消費すると定義する．|
|`add_same(u, v, group, cost)`|$u$ と $v$ がともに集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost}(\leq 0)$ を消費すると定義する．|
|`add(ver, group, cost)`|$\mathrm{ver}$ が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost}$ を消費すると定義する．|
|`solve()`|最小コスト|


## 参考

- https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
- https://ei1333.github.io/algorithm/dinic.html


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2903/review/4099641/emthrm/C++14
