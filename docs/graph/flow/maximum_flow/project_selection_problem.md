---
title: project selection problem
documentation_of: graph/flow/maximum_flow/project_selection_problem.hpp
---


## 計算量

[最大流](maximum_flow.md)に同じ．


## 使用法

||説明|
|:--:|:--:|
|`ProjectSelectionProblem<最大流, T>(n)`|頂点数 $N$ の project selection problem を考える．|
|`add_neq(u, v, cost)`|$u$ が集合 $0$, $v$ が集合 $1$ に属するならばコスト $\mathrm{cost} \geq 0$ かかると定義する．|
|`add(v, group, cost)`|$v$ が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost}$ かかると定義する．|
|`add_or(v, group, cost)`|集合 $\mathrm{group}$ に属する頂点 $v \in V$ が存在するならばコスト $\mathrm{cost} \geq 0$ かかると定義する．|
|`add_or(u, v, group, cost)`|$u, v$ のいずれかまたは両方が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \geq 0$ かかると定義する．|
|`add_eq(v, group, cost)`|$V$ に属する頂点すべてが集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \leq 0$ かかると定義する．|
|`add_eq(u, v, group, cost)`|$u, v$ 両方が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \leq 0$ かかると定義する．|
|`solve()`|最小コスト|


## 参考

- https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
- https://ei1333.github.io/algorithm/dinic.html
- https://koyumeishi.hatenablog.com/entry/2021/01/14/052223


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2903/review/5292569/emthrm/C++17
