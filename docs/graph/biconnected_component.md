---
title: 二重頂点連結成分分解 (biconnected component)
documentation_of: graph/biconnected_component.hpp
---

無向グラフから関節点を含まない辺集合に分割することである．

各集合には任意の相異なる3点を始点, 経由点, 終点とする単純パスが存在する．


### block-cut tree

二重頂点連結成分を一つの頂点につぶすことで得られる木である．


### カクタスグラフ (cactus)

任意の辺が高々一つの単純閉路に含まれる，すなわち任意の異なる単純閉路が高々一つの共通頂点をもつグラフである．

任意の二重頂点連結成分は橋または単純閉路となる．

e.g. 任意の閉路長が奇数となるグラフ


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$

重量版 $O(\lvert V \rvert \log{\lvert V \rvert} + \lvert E \rvert)$ ?


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`BiconnectedComponent(graph, 重量版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重頂点連結成分分解 を考える．|[lowlink](lowlink.md)|
|`block[i]`|縮約後のグラフのブロック $i$ に含まれる辺||
|`id[i]`|元のグラフの頂点 $i$ を含むブロック|重量版のみ|
|`vertices[i]`|縮約後のグラフのブロック $i$ に含まれる頂点|重量版のみ|
|`cutpoint[i]`|元のグラフの関節点 $i$ を含むブロック|重量版のみ|


## 参考

- https://www.learning-algorithms.com/entry/2018/03/21/152148
- https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
- https://codeforces.com/blog/entry/14832

カクタスグラフ
- https://pekempey.hatenablog.com/entry/2017/03/28/203856


## Verified

https://atcoder.jp/contests/arc045/submissions/9253901
