---
title: 有向非巡回グラフ上の到達可能性判定
documentation_of: //include/emthrm/graph/reachability_on_dag.hpp
---


## 時間計算量

ワードサイズを $W$ とおくと $O\left(\frac{Q(\lvert V \rvert + \lvert E \rvert)}{W} \right)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<bool> reachability_on_dag(const std::vector<std::vector<Edge<CostType>>>& graph, const std::vector<int>& ss, const std::vector<int>& ts);`|有向非巡回グラフ $\mathrm{graph}$ 上で頂点 $\mathrm{ss}_i$ から頂点 $\mathrm{ts}_i$ に到達できるか。|


## 参考文献

- https://ei1333.github.io/library/graph/others/offline-dag-reachability.hpp


## Submissons

https://atcoder.jp/contests/typical90/submissions/25153847
