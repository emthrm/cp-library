---
title: 区間に辺を張るテク
documentation_of: include/emthrm/graph/noshi_graph.hpp
---


## 時間計算量

$O(\log{\lvert V \rvert})$


## 仕様

|名前|効果・戻り値|
|:--|:--|
|`NoshiGraph<CostType>(n)`|頂点数 $n$ のグラフを考える。|
|`add_edge(src, dst, cost = 0)`|始点 $\mathrm{src}$、終点 $\mathrm{dst}$、コスト $\mathrm{cost}$ の辺を加える。|
|`add_edge(src_l, src_r, dst_l, dst_r, cost)`|始点 $s \in \lbrace \mathrm{src\_l}, \mathrm{src\_l} + 1, \ldots, \mathrm{src\_r} - 1 \rbrace$、終点 $t \in \lbrace \mathrm{dst\_l}, \mathrm{dst\_l} + 1, \ldots, \mathrm{dst\_r} - 1 \rbrace$、コスト $\mathrm{cost}$ の辺を加える。|


## 参考文献

- https://twitter.com/noshi91/status/1193177214453338113
- https://twitter.com/noshi91/status/1272380264396648448
- https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656


## Submissons

https://codeforces.com/contest/786/submission/100222769
