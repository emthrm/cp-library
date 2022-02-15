---
title: 最小流量制約付き最小費用流
documentation_of: graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
---


## 計算量

[最小費用流](minimum_cost_flow.md)に同じ．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`MinimumCostFlowWithLowerBoundConstraint<最小費用流, フロー, コスト>(n, 十分大きな定数, ∞)`|頂点数 $N$ の最小流量制約付き最小費用流を考える．||
|`uinf`|$\infty$|型はコストと等しい．|
|`add_edge(src, dst, lb, ub, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 流量の下限 $\mathrm{lb}$, 上限 $\mathrm{ub}$, コスト $\mathrm{cost}$ の辺を加える．||
|`solve(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せないときは $\infty$ となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，p.204，マイナビ出版（2012）


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14
