---
title: HL 分解 (heavy-light decomposition)
documentation_of: graph/tree/hld.hpp
---

heavy edge と light edge に分類された辺を基に木を分解する手法である．


## 時間計算量

$\langle O(\lvert V \rvert), O(\log{\lvert V \rvert}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`HLD<CostType>(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ の HL 分解を考える．|
|`parent[i]`|頂点 $i$ の親の頂点番号|
|`subtree[i]`|頂点 $i$ の部分木の大きさ|
|`id[i]`|HL 分解後の頂点 $i$ の ID|
|`inv[i]`|HL 分解前の ID $i$ の頂点番号|
|`head[i]`|頂点 $i$ を含む heavy path の先頭の頂点番号|
|`cost[i]`|辺 (`inv[i]`, `inv[i + 1]`) の重み|
|`v_update(u, v, f)`|頂点 $u, v$ 間の頂点に対して $f$ を基に更新する．|
|`v_query(u, v, f, g, 単位元)`|頂点 $u, v$ 間の頂点における $f$ を基に $g$ でまとめたクエリの解|
|`subtree_v_update(ver, f)`|頂点 $ver$ の部分木の頂点に対して $f$ を基に更新する．|
|`subtree_v_query<T>(ver, f)`|頂点 $ver$ の部分木の頂点における $f$ を基にしたクエリの解|
|`e_update(u, v, f)`|頂点 $u, v$ 間の辺に対して $f$ を基に更新する．|
|`e_query(u, v, f, g, 単位元)`|頂点 $u, v$ 間の辺における $f$ を基に $g$ でまとめたクエリの解|
|`subtree_e_update(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する．|
|`subtree_e_query<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺における $f$ を基にしたクエリの解|
|`lca(u, v)`|頂点 $u, v$ の[最小共通祖先](lca.md)|


## 参考

- https://www.slideshare.net/hcpc_hokudai/study-20150107
- http://beet-aizu.hatenablog.com/entry/2017/12/12/235950
- https://github.com/beet-aizu/library/blob/master/tree/heavylightdecomposition.cpp
- https://codeforces.com/blog/entry/53170


## ToDo

- 高速化
  - http://yosupo.hatenablog.com/entry/2015/10/02/233244


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084766/emthrm/C++14
- [最小共通祖先](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
