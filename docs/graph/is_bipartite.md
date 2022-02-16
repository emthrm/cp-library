---
title: 二部グラフ判定
documentation_of: graph/is_bipartite.hpp
---


### 二部グラフ (bipartite graph)

- 各部分集合内の頂点間で辺が存在しないように，頂点集合を二つの部分集合に分割できるグラフである．
- [彩色数](chromatic_number.md) $2$ のグラフである．
- 奇数長の閉路を含まないグラフである．

これらはすべて同値である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`is_bipartite(graph, &color)`|グラフ $\mathrm{graph}$ は二部グラフであるか．|$\mathrm{color} \in {\lbrace 0, 1 \rbrace}^N$ は各頂点の色を表す．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.93-94，マイナビ出版（2012）


## Verified

https://atcoder.jp/contests/arc099/submissions/26050245
