---
title: 拡張 Euclid の互除法 (extended Euclidean algorithm)
documentation_of: math/ext_gcd.hpp
---

$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$ を求めるアルゴリズムである．


## 時間計算量

$O(\log{\max \lbrace A, B \rbrace})$


## 使用法

||説明|
|:--:|:--:|
|`ext_gcd(a, b)`|$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$|


## 参考

- https://qiita.com/drken/items/b97ff231e43bce50199a


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_E/review/4088355/emthrm/C++14
