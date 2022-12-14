---
title: 拡張 Euclid の互除法 (extended Euclidean algorithm)
documentation_of: include/emthrm/math/ext_gcd.hpp
---

$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$ を求めるアルゴリズムである．

$ax + by = c \cdot \mathrm{gcd}(a, b)$ の特殊解を $(x, y) = (x^{\prime}, y^{\prime})$ とすると，一般解は $k \in \mathrm{Z}$ を用いて $(x, y) = \left(x^{\prime} + k \frac{b}{\mathrm{gcd}(a, b)}, y^{\prime} - k \frac{a}{\mathrm{gcd}(a, b)}\right)$ と表せる．


## 時間計算量

$O(\log{\max \lbrace A, B \rbrace})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`ext_gcd(a, b)`|$ax + by = \gcd(a, b)$ を満たす整数解 $(x, y)$|$a \neq 0,\ b \neq 0$ のとき $\lvert x \rvert \leq \left\lvert \frac{b}{\mathrm{gcd}(a, b)} \right\rvert,\ \lvert y \rvert \leq \left\lvert \frac{a}{\mathrm{gcd}(a, b)} \right\rvert$ が成り立つ．|


## 参考

- https://qiita.com/drken/items/b97ff231e43bce50199a
- https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
- https://ja.wikipedia.org/wiki/%E3%83%99%E3%82%BA%E3%83%BC%E3%81%AE%E7%AD%89%E5%BC%8F
- https://scol.hatenablog.com/entry/2019/10/19/180000
- https://divinejk.hatenablog.com/entry/2021/02/28/233332


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_E/review/5272349/emthrm/C++17
