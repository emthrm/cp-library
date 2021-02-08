---
title: トポロジカルソート (topological sort)
documentation_of: graph/topological_sort.hpp
---

有向非巡回グラフ (DAG) のトポロジカル順序を求めるアルゴリズムである．


### トポロジカル順序

$i$ 番目の頂点 $V_i$ について $V_i$ から $V_j$ に向かう辺があるとき
$i < j$ が成り立つ頂点の番号の付け方である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`topological_sort(graph)`|グラフ $\mathrm{graph}$ のトポロジカル順序|存在しない場合は空配列となる．|


## 参考

- https://github.com/spaghetti-source/algorithm/blob/master/graph/topological_sort.cc


## ToDo

- DAG の到達可能性
  - https://github.com/ei1333/library/blob/master/graph/offline-dag-reachability.cpp


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_4_B/review/4082498/emthrm/C++14
