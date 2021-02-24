---
title: double sweep
documentation_of: graph/tree/double_sweep.hpp
---

木の直径を求めるアルゴリズムである．


### 木の直径

木の最遠頂点間の距離である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`double_sweep(graph)`|グラフ $\mathrm{graph}$ の直径の長さと直径|


## 参考

- http://www.prefield.com/algorithm/graph/tree_diameter.html


## ToDo

- 頂点の重みを基にした直径
  - https://github.com/beet-aizu/library/blob/master/tree/diameterforvertex.cpp


## Verified

https://judge.yosupo.jp/submission/40074
