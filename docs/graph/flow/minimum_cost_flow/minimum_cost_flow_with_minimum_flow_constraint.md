---
title: 最小流量制約付き最小費用流
documentation_of: graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp
---


## 計算量

[最小費用流](minimum_cost_flow.md)に同じ．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`MinimumCostFlowWithMinimumFlowConstraint<最小費用流, フロー, コスト>(n, 十分大きな定数, ∞, ∞)`|頂点数 $N$ の最小流量制約付き最小費用流を考える．||
|`add_edge(src, dst, lb, ub, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 流量の下限 $\mathrm{lb}$, 上限 $\mathrm{ub}$, コスト $\mathrm{cost}$ の辺を張る．||
|`solve(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せない場合は $\infty$ となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] p.204


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14

