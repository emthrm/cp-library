---
title: 二部グラフ判定
documentation_of: graph/is_bipartite.hpp
---


### 二部グラフ (bipartite graph)

- 各部分集合内の頂点間で辺が存在しないように頂点集合を二つの部分集合に分割できるグラフである．
- 隣接するものは異なる色となるように頂点を塗る彩色問題において彩色数が2となるグラフ．
- 奇数長の閉路を含まないグラフである．

これらはすべて同値である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`is_bipartite(graph, color)`|グラフ $\mathrm{graph}$ は二部グラフであるか．|$\mathrm{color}$ は各頂点の色 $-1$/$1$ でなければならない．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.93-94


## Verified

https://atcoder.jp/contests/code-festival-2017-qualb/submissions/9246218
