---
title: 二部グラフ判定
documentation_of: //include/emthrm/graph/is_bipartite.hpp
---


### 二部グラフ (bipartite graph)

- 各部分集合内の頂点間で辺が存在しないように、頂点集合を二つの部分集合に分割できるグラフである。
- [彩色数](chromatic_number.md) $2$ のグラフである。
- 奇数長の閉路を含まないグラフである。

これらはすべて同値である。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

|名前|戻り値|備考|
|:--|:--|:--|
|`template <typename CostType>`<br>`std::vector<int> is_bipartite(const std::vector<std::vector<Edge<CostType>>>& graph);`|隣接する頂点の色が同じにならないよう、無向グラフ $\mathrm{graph}$ を $2$ 色に塗り分けたときの各頂点の色。ただし二部グラフでなければ空配列を返す。|色は $0$ または $1$ で表す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.93-94，マイナビ出版（2012）


## Submissons

https://atcoder.jp/contests/arc099/submissions/26050245
