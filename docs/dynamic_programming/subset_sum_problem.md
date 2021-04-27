---
title: 部分和問題 (subset sum problem)
documentation_of: dynamic_programming/subset_sum_problem.hpp
---

$n$ 個の数の選び方の内，要素の和が特定の数となるものの存在性を判定する問題である．

ナップサック問題の部分問題である．

[形式的冪級数](../math/formal_power_series/formal_power_series.md)を用いて場合の数を求めることができる．


## 時間計算量

$O(N + D\log{D})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`subset_sum_problem(a, d)`|集合内の要素の和が $0 \leq i \leq D$ となる $A$ の部分集合の個数|$A_i \geq 0$ でなければならない．|


## 参考

- https://yukicoder.me/wiki/polynomial_techniques


## Verified

https://judge.yosupo.jp/submission/6908
