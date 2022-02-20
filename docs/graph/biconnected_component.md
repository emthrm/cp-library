---
title: 二重頂点連結成分 (biconnected component) 分解
documentation_of: graph/biconnected_component.hpp
---

無向グラフを関節点の存在しない辺集合に分割することである．

それぞれの成分には，任意の相異なる3点を始点・経由点・終点とする単純パスが存在する．


### block-cut tree

二重頂点連結成分を一つの頂点に縮約することで得られる木である．


### カクタスグラフ (cactus)

任意の辺が高々一つの単純閉路に含まれる，すなわち任意の異なる単純閉路が高々一つの共通頂点をもつグラフである．

任意の二重頂点連結成分は橋または単純閉路となる．

e.g. 任意の閉路長が奇数となるグラフ


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$

完全版 $O(\lvert V \rvert \log{\lvert V \rvert} + \lvert E \rvert)$ ?


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`BiconnectedComponent(graph, 完全版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重頂点連結成分分解を考える．||
|`id[i]`|元のグラフの頂点 $i$ を含むブロック|関節点のときは $-1$ である．<br>完全版のみ|
|`vertices[i]`|縮約後のグラフのブロック $i$ に含まれる頂点|完全版のみ|
|`cutpoint[i]`|元のグラフの関節点 $i$ を含むブロック|完全版のみ|
|`block[i]`|縮約後のグラフのブロック $i$ に含まれる辺||


## 参考

- https://www.learning-algorithms.com/entry/2018/03/21/152148
- https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
- https://codeforces.com/blog/entry/14832

カクタスグラフ
- https://pekempey.hatenablog.com/entry/2017/03/28/203856


## ToDo

- https://judge.yosupo.jp/problem/biconnected_components


## Verified

https://atcoder.jp/contests/arc045/submissions/9253901
