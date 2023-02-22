---
title: 巡回セールスマン問題 (traveling salesman problem)
documentation_of: include/emthrm/graph/traveling_salesman_problem.hpp
---

重み付き有向グラフに対してコスト最小のハミルトン閉路を求める問題である。


## 時間計算量

$O(2^{\lvert V \rvert} {\lvert V \rvert}^2)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`CostType traveling_salesman_problem(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|グラフ $\mathrm{graph}$ の巡回セールスマン問題の解のコスト。ただし解が存在しないときは $\infty$ を返す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.173-175，マイナビ出版（2012）


## TODO

- 最短のハミルトン路
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E8%B7%AF
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E9%96%89%E8%B7%AF%E5%95%8F%E9%A1%8C
  - http://www.prefield.com/algorithm/graph/shortest_hamilton_path.html
  - https://github.com/primenumber/ProconLib/blob/master/Graph/ShortestHamiltonPath.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/hamilton_cycle_ore.cc


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_2_A/review/5219970/emthrm/C++17
