---
title: 補グラフの連結成分分解
documentation_of: include/emthrm/graph/connencted_component_of_complement_graph.hpp
---


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`UnionFind connencted_component_of_complement_graph(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ の補グラフの連結成分分解|


## 参考文献

- https://betrue12.hateblo.jp/entry/2020/02/24/165627


## Submissons

https://codeforces.com/contest/1242/submission/113385795
