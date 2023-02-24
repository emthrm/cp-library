---
title: トポロジカルソート (topological sort)
documentation_of: //include/emthrm/graph/topological_sort.hpp
---

有向非巡回グラフ (directed acyclic graph) のトポロジカル順序を求めるアルゴリズムである。


### トポロジカル順序

$i$ 番目の頂点 $V_i$ に対して辺 $(V_i, V_j)$ が存在するならば $i < j$ を満たすような頂点の番号の付け方である。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<int> topological_sort(const std::vector<std::vector<Edge<CostType>>>& graph);`|グラフ $\mathrm{graph}$ のトポロジカル順序。ただし存在しないときは空配列を返す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.89-90，マイナビ出版（2012）
- https://github.com/spaghetti-source/algorithm/blob/8b1daaa3e80e5d954aac2632ef2299b1b86c55ed/graph/topological_sort.cc


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_4_B/review/4082498/emthrm/C++14
