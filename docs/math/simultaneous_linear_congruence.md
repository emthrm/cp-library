---
title: 連立線形合同式 (simultaneous linear congruence)
documentation_of: math/simultaneous_linear_congruence.hpp
---

$$A_i x \equiv B_i \pmod{M_i} \ (i = 1, 2,\ldots, N) \text{．}$$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`simultaneous_linear_congruence(a, b, m)`|$mk + x \ (k \in \mathbb{Z},\ 0 \leq x < m) \text{ s.t. } A_i x \equiv B_i \pmod{M_i}$|存在しない場合は $(0, -1)$ となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.261-262，マイナビ出版（2012）．


## Verified

https://yukicoder.me/submissions/701737
