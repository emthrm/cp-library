---
title: 有向非巡回グラフ上の到達可能性判定
documentation_of: graph/reachability_on_dag.hpp
---


## 時間計算量

ワードサイズを $W$ とおくと $O\left(\frac{Q(\lvert V \rvert + \lvert E \rvert)}{W} \right)$．


## 使用法

||説明|
|:--:|:--:|
|`reachability_on_dag(graph, src, dst)`|有向非巡回グラフ $\mathrm{graph}$ 上で頂点 $\mathrm{src}_i$ から頂点 $\mathrm{dst}_i$ に到達できるか．|


## 参考

- https://ei1333.github.io/library/graph/others/offline-dag-reachability.hpp


## Verified

https://atcoder.jp/contests/typical90/submissions/25153847