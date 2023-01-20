---
title: 区間に辺を張るテク
documentation_of: include/emthrm/graph/noshi_graph.hpp
---


## 時間計算量

$O(\log{\lvert V \rvert})$


## 仕様

```cpp
template <typename CostType>
struct NoshiGraph;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<std::vector<Edge<CostType>>> graph`|有向グラフ|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit NoshiGraph(const int n);`|頂点数 $n$ のオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const CostType cost = 0);`|コスト $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える。|
|`add_edge(src_l, src_r, dst_l, dst_r, cost);`|コスト $\mathrm{cost}$ の辺 $(s, t)$ ($s \in \lbrace \mathrm{src\_l}, \ldots, \mathrm{src\_r} - 1 \rbrace,\ t \in \lbrace \mathrm{dst\_l}, \ldots, \mathrm{dst\_r} - 1 \rbrace$) を加える。|


## 参考文献

- https://twitter.com/noshi91/status/1193177214453338113
- https://twitter.com/noshi91/status/1272380264396648448
- https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656


## Submissons

https://codeforces.com/contest/786/submission/100222769
