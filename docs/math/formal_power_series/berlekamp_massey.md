---
title: Berlekamp–Massey algorithm
documentation_of: math/formal_power_series/berlekamp-massey.hpp
---

任意の体上で線形回帰数列 (linear recurrence sequence) の特性多項式を求められるアルゴリズムである．


## 時間計算量

$O(N^2)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`berlekamp-massey(s)`|$S(x) = \frac{P(x)}{Q(x)} \bmod{x^n}$ を満たす最小次数の $Q(x)$？|${\lbrack x^0 \rbrack}Q = 1$<br>$\mathrm{deg}(P) < \mathrm{deg}(Q) = d$ を満たす $\frac{P(x)}{Q(x)}$ を想定するならば $n \geq 2d$ でなければならない．|


## 実装

入力を $S \mathrel{:=} (S_0, S_1, \ldots)$ とおく．数列 $C$ に対して

$$C(i) \mathrel{:=} \begin{cases} \sum_{k = 0}^{\lvert C \rvert - 1} C_k S_{i - k} & (i \geq \lvert C \rvert - 1), \\ 0 & (\text{otherwise}) \end{cases}$$

とおく．任意の $i \in \mathbb{N}$ に対して $C(i) = 0$ が成り立つ $C$ を求めたい．

初期値 $C \gets (1)$ とする．$n$ 番目 (0-based) のイテレーションを考える．$\lvert C \rvert \mathrel{:=} l$ とおき，任意の $i \in \lbrace 0, 1, \ldots, n - 1 \rbrace$ に対して $C(i) = 0$ が成り立つとする．

$\Delta_n \mathrel{:=} C(n)$ とおく．$\Delta_n \neq 0$ を仮定する．

$$D(i) = \begin{cases} 0 & (i = 0, 1, \ldots, n - 1), \\ -\Delta_n & (i = n) \end{cases}$$

を満たす $D$ を求めたい．

$\Delta_f \neq 0$ を満たす $f < n$ を一つとる（$n = \min \lbrace i \in \mathbb{N} \mid S_i \neq 0 \rbrace$ のときは後述する）．$f$ 番目のイテレーションのときの $C$ を $B$ とおく．

$$B(i) = \begin{cases} 0 & (i = 0, 1, \ldots, f - 1), \\ \Delta_f & (i = f) \end{cases}$$

が成り立つ．

$$D_i \mathrel{:=} \begin{cases} 0 & (i = 0, 1, \ldots, n - f - 1), \\ -\frac{\Delta_n}{\Delta_f} B_{i - (n - f)} & (i = n - f, n - f + 1, \ldots, n - f + \lvert B \rvert - 1) \end{cases}$$

とおくと

$$\begin{split} D(i) &= \sum_{k = 0}^{n - f + \lvert B \rvert - 1} D_k C_{i - k} \\ &= \sum_{k = n - f}^{n - f + \lvert B \rvert - 1} D_k C_{i - k} \\ &= \sum_{k = 0}^{\lvert B \rvert - 1} -\frac{\Delta_n}{\Delta_f} B_k C_{i - (k + n - f)} \\ &= -\frac{\Delta_n}{\Delta_f} \sum_{k = 0}^{\lvert B \rvert - 1} B_k C_{(i - (n - f)) - k} \\ &= -\frac{\Delta_n}{\Delta_f} B(i - (n - f)) \\ &= \begin{cases} 0 & (i = 0, 1, \ldots, n - f - 1) \\ 0 & (i = n - f, n - f + 1, \ldots, n - 1) \\ -\frac{\Delta_n}{\Delta_f} \cdot \Delta_f = -\Delta_n & (i = n) \end{cases} \end{split}$$

となり，条件を満たす．

$m \mathrel{:=} \lvert D \rvert = n - f + \lvert B \rvert$ とおく．
- $m > l$ のとき，$C \gets (C_0 + D_0, C_1 + D_1, \ldots, C_{l - 1} + D_{l - 1}, D_{l}, D_{l + 1}, \ldots, D_{m - 1})$ と更新すればよい．
- $m \leq l$ のとき，$C \gets (C_0 + D_0, C_1 + D_1, \ldots, C_{m - 1} + D_{m - 1}, C_m, C_{m + 1} \ldots, C_{l - 1})$ と更新すればよい．

$n = \min \lbrace S_i \neq 0 \mid i \in \mathbb{N} \rbrace$ のとき，$C^\prime_0 \neq 0$ かつ $\lvert C^\prime \rvert \leq n + 1$ を満たす任意の数列 $C^\prime$ に対して $C^\prime(n) \neq 0$ が成り立つ．$\lvert C \rvert > n + 1$ を満たすように更新しなければならない．実装では $C \gets (1, 0, 0, \ldots, 0, -\Delta_n)$ と更新するように初期値を設定している．


## 参考

- https://en.wikipedia.org/wiki/Berlekamp%E2%80%93Massey_algorithm
- https://mzhang2021.github.io/cp-blog/berlekamp-massey/
- https://37zigen.com/berlekamp-massey/
- https://nyaannyaan.github.io/library/fps/berlekamp-massey.hpp


## Verified

https://judge.yosupo.jp/submission/80147
