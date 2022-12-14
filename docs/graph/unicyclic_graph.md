---
title: unicyclic graph / 1-tree
documentation_of: include/emthrm/graph/unicyclic_graph.hpp
---

閉路をただ一つだけ含む単純連結無向グラフである．俗に[ある漫画家の名前を用いて表現される](https://twitter.com/chokudai/status/772440823170379776)．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`UnicyclicGraph<CostType>(n)`|頂点数 $N$ の unicyclic graph を考える．||
|`is_in_loop[i]`|頂点 $i$ は閉路に含まれるか．||
|`belong[i]`|頂点 $i$ を含む木の番号|存在しないときは $-1$ となる．|
|`mapping[i]`|頂点 $i$ に対応する木の頂点番号|存在しないときは $-1$ となる．|
|`loop`|閉路||
|`invs[i][j]`|木 $i$ の頂点 $j$ に対応する元のグラフの頂点番号||
|`forests`|閉路を除いた森||
|`add_edge(src, dst, cost = 0)`|始点 $\mathrm{src}$，終点 $\mathrm{dst}$，コスト $\mathrm{cost}$ の辺を加える．|||
|`build()`|構築する．||


## 参考

- https://en.wikipedia.org/wiki/Pseudoforest


## Verified

https://yukicoder.me/submissions/649654
