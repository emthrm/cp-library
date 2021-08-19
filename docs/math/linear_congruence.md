---
title: 連立線形合同式 (linear congruence)
documentation_of: math/linear_congruence.hpp
---

$$A_i x \equiv B_i \pmod{M_i} \ (i = 1, 2,\ldots, N) \text{．}$$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`linear_congruence(a, b, m)`|$mk + x \ (k \in \mathbb{Z}) \text{ s.t. } A_i x \equiv B_i \pmod{M_i}$|存在しない場合は $(0, -1)$ となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.261-262，マイナビ出版（2012）．


## Verified

https://atcoder.jp/contests/ddcc2019-qual/submissions/9318157
