---
title: 二部グラフ判定
documentation_of: graph/is_bipartite.hpp
---


### 二部グラフ (bipartite graph)

- 各部分集合内の頂点間で辺が存在しないよう，頂点集合を二つの部分集合に分割できるグラフである．
- [彩色数](chromatic_number.md)$2$のグラフである．
- 奇数長の閉路を含まないグラフである．

これらはすべて同値である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`is_bipartite(graph, color)`|グラフ $\mathrm{graph}$ は二部グラフであるか．|$\mathrm{color} \in {\lbrace 0, 1 \rbrace}^N$ は各頂点の色を表す．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.93-94


## Verified

https://atcoder.jp/contests/code-festival-2017-qualb/submissions/9246218
