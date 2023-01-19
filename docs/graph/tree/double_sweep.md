---
title: double sweep
documentation_of: include/emthrm/graph/tree/double_sweep.hpp
---

木の直径を求めるアルゴリズムである。


### 木の直径

木の最遠頂点間距離である。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType> std::pair<CostType, std::vector<int>> double_sweep(const std::vector<std::vector<Edge<CostType>>>& graph);`|グラフ $\mathrm{graph}$ の直径とその経路|


## 参考文献

- http://www.prefield.com/algorithm/graph/tree_diameter.html


## TODO

- 頂点の重みを基にした直径
  - https://github.com/beet-aizu/library/blob/master/tree/diameterforvertex.cpp


## Submissons

https://judge.yosupo.jp/submission/40074
