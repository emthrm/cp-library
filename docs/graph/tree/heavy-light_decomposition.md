---
title: HL 分解 (heavy-light decomposition)
documentation_of: graph/tree/heavy-light_decomposition.hpp
---

heavy edge と light edge に分類された辺を基にして，木を分解する方法である．


## 時間計算量

$\langle O(\lvert V \rvert), O(\log{\lvert V \rvert}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`HeavyLightDecomposition<CostType>(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ の HL 分解を考える．|
|`parent[i]`|頂点 $i$ の親の頂点番号|
|`subtree[i]`|頂点 $i$ の部分木の大きさ|
|`id[i]`|頂点 $i$ の ID|
|`inv[i]`|ID $i$ の頂点番号|
|`head[i]`|頂点 $i$ を含む heavy path の先頭の頂点番号|
|`cost[i]`|辺 (`inv[i]`, `inv[i + 1]`) の重み|
|`update_v(u, v, f)`|頂点 $u, v$ 間の頂点に対して $f$ を基に更新する．|
|`query_v(u, v, f, g, 単位元)`|頂点 $u, v$ 間の頂点に対する $f$ を基に $g$ でまとめたクエリの解|
|`update_subtree_v(ver, f)`|頂点 $ver$ の部分木の頂点に対して $f$ を基に更新する．|
|`query_subtree_v<T>(ver, f)`|頂点 $ver$ の部分木の頂点に対する $f$ を基にしたクエリの解|
|`update_e(u, v, f)`|頂点 $u, v$ 間の辺に対して $f$ を基に更新する．|
|`query_e(u, v, f, g, 単位元)`|頂点 $u, v$ 間の辺に対する $f$ を基に $g$ でまとめたクエリの解|
|`update_subtree_e(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する．|
|`query_subtree_e<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対する $f$ を基にしたクエリの解|
|`lowest_common_ancestor(u, v)`|頂点 $u, v$ の[最小共通祖先](lowest_common_ancestor.md)|


## 参考

- https://www.slideshare.net/hcpc_hokudai/study-20150107
- http://beet-aizu.hatenablog.com/entry/2017/12/12/235950
- https://github.com/beet-aizu/library/blob/627950ae389af108b3c3f431f057c58891b0ba72/tree/heavylightdecomposition.cpp
- https://codeforces.com/blog/entry/53170


## ToDo

- 高速化
  - http://yosupo.hatenablog.com/entry/2015/10/02/233244


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084766/emthrm/C++14
