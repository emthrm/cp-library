---
title: 巡回セールスマン問題 (traveling salesman problem)
documentation_of: graph/tsp.hpp
---

重み付き有向グラフについてすべての頂点を一度ずつ通る閉路の最小コストを求める問題である．


## 時間計算量

$O(2^{\lvert V \rvert} {\lvert V \rvert}^2)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`tsp(graph, ∞)`|グラフ $\mathrm{graph}$ の巡回セールスマン問題の解|存在しない場合は $\infty$ となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.173-175


## ToDo

- 最短のハミルトン路
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E8%B7%AF
  - https://ja.wikipedia.org/wiki/%E3%83%8F%E3%83%9F%E3%83%AB%E3%83%88%E3%83%B3%E9%96%89%E8%B7%AF%E5%95%8F%E9%A1%8C
  - http://www.prefield.com/algorithm/graph/shortest_hamilton_path.html
  - https://github.com/primenumber/ProconLib/blob/master/Graph/ShortestHamiltonPath.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/hamilton_cycle_ore.cc


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_2_A/review/5219970/emthrm/C++17
