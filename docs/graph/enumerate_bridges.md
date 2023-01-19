---
title: 橋の検出
documentation_of: include/emthrm/graph/enumerate_bridges.hpp
---


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType> std::vector<Edge<CostType>> enumerate_bridges(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ の橋|


## 参考文献

- https://www.slideshare.net/chokudai/arc039


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082847/emthrm/C++14
