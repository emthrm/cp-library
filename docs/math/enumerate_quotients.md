---
title: 商の列挙
documentation_of: //include/emthrm/math/enumerate_quotients.hpp
---


## 時間計算量

$O(\sqrt{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::tuple<T, T, T>> enumerate_quotients(const T n);`|$\lbrace (l, r, q) \mid \forall x \in \lbrace l, l + 1, \ldots, r - 1 \rbrace,\ \lfloor \frac{n}{x} \rfloor = q \rbrace$|


## 備考

1. $\left\lfloor \frac{N}{i} \right\rfloor = q$ を満たす $i$ の範囲は $\left(\left\lfloor \frac{N}{q + 1} \right\rfloor, \left\lfloor \frac{N}{q} \right\rfloor \right\rbrack$ を満たす。
2. $N \in \mathbb{N}^+$ に対して商を昇順に並べたものを $Q \mathrel{:=} (q_1, q_2, \ldots, q_k)$ ($k \in \mathbb{N}^+,\ q_1 < q_2 < \cdots < q_k$) とおく。$x \in Q$ に対して
   - $x^2 \leq N$ ならば $x = q_x$ が成り立ち、
   - $x^2 \geq N$ ならば $x = q_{k + 1 - N / x}$ が成り立つ。


## 参考文献

- https://twitter.com/noshi91/status/1278227768333852672

備考1
- https://twitter.com/heno_code/status/1495040694527741954

備考2
- https://twitter.com/maspy_stars/status/1495039893172412421


## Submissons

https://judge.yosupo.jp/submission/137127
