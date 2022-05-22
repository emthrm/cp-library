---
title: sum of floor of linear
documentation_of: math/floor_sum.hpp
---

$$
  \sum_{i = 0}^{N - 1} \left\lfloor \frac{Ai + B}{M} \right\rfloor
$$


## 時間計算量

$O(\log{M})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`floor_sum(a, b, m, n)`|$\sum_{i = 0}^{N - 1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$|$M \in \mathbb{N}^+$|


## 参考

- https://rsk0315.hatenablog.com/entry/2020/12/13/231307
- https://qiita.com/R_olldIce/items/3e2c80baa6d5e6f3abe9#4-floor_sum
- https://github.com/atcoder/ac-library/blob/c8e527063415e2f9aaf87cf80f2c59730a46ed98/atcoder/math.hpp#L82-L97
- https://github.com/atcoder/ac-library/blob/6c88a70c8f95fef575af354900d107fbd0db1a12/atcoder/internal_math.hpp#L180-L207


## Verified

https://judge.yosupo.jp/submission/39036
