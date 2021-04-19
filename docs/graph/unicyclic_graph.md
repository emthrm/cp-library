---
title: unicyclic graph (1-tree)
documentation_of: graph/unicyclic_graph.hpp
---

閉路をただ一つだけ含む単純連結無向グラフである．俗に[ある漫画家の名前を用いて表現される](https://twitter.com/chokudai/status/772440823170379776)．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`UnicyclicGraph<CostType>(n)`|頂点数 $n$ の unicyclic graph を考える．||
|`loop`|閉路||
|`is_in_loop[i]`|頂点 $i$ は閉路に含まれるか．||
|`forest`|閉路を除いた森||
|`belong[i]`|頂点 $i$ を含む木の番号|存在しない場合は $-1$ となる．|
|`mp[i]`|頂点 $i$ に対応する木の頂点番号|存在しない場合は $-1$ となる．|
|`inv[i][j]`|木 $i$ の頂点 $j$ に対応する元のグラフの頂点番号||


## 参考

- https://en.wikipedia.org/wiki/Pseudoforest


## Verified

https://yukicoder.me/submissions/649654
