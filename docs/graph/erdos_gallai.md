---
title: エルデシュ・ガライの定理 (Erdős–Gallai theorem)
documentation_of: graph/erdos_gallai.hpp
---

$$\text{降順の次数列 } d_1, d_2,\ldots, d_n \text{ を実現する単純無向グラフが存在する} \\ \Leftrightarrow \begin{cases} \sum_{i = 1}^n d_i \equiv 0 \pmod{2} \\ \sum_{i = 1}^k d_i \leq k(k-1) + \sum_{i = k+1}^n \min(d_i, k) \ (k = 1, 2,\ldots, n) \text{．} \end{cases}$$


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 使用法

||説明|
|:--:|:--:|
|`erdos_gallai(degree)`|次数列を $\mathrm{degree}$ とする無向単純グラフが存在するか|


## 参考

- https://mathtrain.jp/shakehands


## Verified

https://atcoder.jp/contests/yahoo-procon2018-qual/submissions/9252185
