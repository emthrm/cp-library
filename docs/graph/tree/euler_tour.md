---
title: オイラーツアー (Euler tour)
documentation_of: graph/tree/euler_tour.hpp
---

根付き木を列として表現するデータ構造である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`EulerTour(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ のオイラーツアーを考える．|
|`tour`|頂点属性のオイラーツアー|
|`left[i]`|`tour` において頂点 $i$ が登場するインデックスの最小値|
|`right[i]`|`tour` において頂点 $i$ が登場するインデックスの最大値|
|`down[i]`|`cost` において頂点 $i$ に下る辺が登場するインデックス|
|`up[i]`|`cost` において頂点 $i$ から上る辺が登場するインデックス|
|`depth[i]`|頂点 `tour[i]` の深さ|
|`cost`|辺属性のオイラーツアー|
|`v_update(ver, f)`|頂点 $\mathrm{ver}$ の部分木の頂点に対して $f$ を基に更新する．|
|`v_query<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の頂点における $f$ を基にしたクエリの解|
|`e_query<T>(u, v, f)`|頂点 $u$ から $v$ へ下る辺における $f$ を基にしたクエリの解|
|`subtree_e_update(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する．|
|`subtree_e_query<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺における $f$ を基にしたクエリの解|


## 参考

- http://beet-aizu.hatenablog.com/entry/2019/07/08/174727
- https://github.com/spaghetti-source/algorithm/blob/41bc0bbb1767692eb9bdeeceb332b2b8cc17329a/graph/least_common_ancestor_sparsetable.cc


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14
