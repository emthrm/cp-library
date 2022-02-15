---
title: lowlink
documentation_of: graph/lowlink.hpp
---

深さ優先探索木 (depth-first search tree) で訪問時刻を $\mathrm{order}$ とおくと，後退辺 (back edge) を高々一度通ることで到達できる頂点の $\mathrm{order}$ の最小値である．


### 橋 (bridge)

無向グラフ $G = (V, E)$ に対して，グラフ $(V, E \setminus \lbrace e \rbrace)$ が非連結となる辺 $e$ である．


### 関節点 (articulation point)

無向グラフ $G = (V, E)$ に対して，グラフ $(V \setminus \lbrace v \rbrace, E)$ が非連結となる頂点 $v$ である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Lowlink<CostType>(graph)`|無向グラフ $\mathrm{graph}$ の lowlink を考える．||
|`order[i]`|頂点 $i$ の訪問時刻||
|`lowlink`|lowlink||
|`articulation_points`|関節点の集合||
|`bridges`|橋の集合|多重辺に対応していない．|
|`graph`|無向グラフ||


## 参考

- http://kagamiz.hatenablog.com/entry/2013/10/05/005213


## Verified

- [橋](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082818/emthrm/C++14)
- [関節点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_A/review/4082810/emthrm/C++14)
