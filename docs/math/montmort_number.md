---
title: モンモール数 (Montmort number)
documentation_of: math/montmort_number.hpp
---

$$a_n = \begin{cases} 0 & (n = 1) \\ 1 & (n = 2) \\ (n - 1)(a_{n - 1} + a_{n - 2}) & (n \geq 3) \end{cases}$$

となる完全順列の個数 $a_n$ のこと．これを解くと

$$a_n = n! \sum_{k = 2}^n \dfrac{(-1)^k}{k!} \ (n \geq 2)$$

が成り立つ．

母関数

$$M(x) = \dfrac{e^{-x}}{1 - x} \text{．}$$


### 完全順列 (攪乱順列, derangement)

大きさ $N$ の順列 $P$ の内，$P_i \neq i \ (1 \leq \forall i \leq N)$ を満たすものである．


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`montmort<T>(n)`|モンモール数 $a_i \ (1 \leq i \leq n)$ の数表|


## 参考

- https://mathtrain.jp/montmort
- http://kyuridenamida.hatenablog.com/entry/2016/04/27/015414


## Verified

https://judge.yosupo.jp/submission/2731
