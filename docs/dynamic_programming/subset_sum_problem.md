---
title: 部分和問題 (subset sum problem)
documentation_of: include/emthrm/dynamic_programming/subset_sum_problem.hpp
---

$n$ 個の数の選び方の内、要素の和が特定の数となるものの存在性を判定する問題である。

ナップサック問題の部分問題である。

[形式的冪級数](../math/formal_power_series/formal_power_series.md)を用いて場合の数を求められる。


## 時間計算量

$O(N + D\log{D})$


## 仕様

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`subset_sum_problem(a, d)`|集合内の要素の和が $s$ ($0 \leq s \leq D$) となる $A$ の部分集合の個数|$A_i \geq 0$|


## 参考文献

- https://yukicoder.me/wiki/polynomial_techniques


## Submissons

https://judge.yosupo.jp/submission/6908
