---
title: 連立線形合同式 (simultaneous linear congruence)
documentation_of: //include/emthrm/math/simultaneous_linear_congruence.hpp
---

$$
  A_i x \equiv B_i \pmod{M_i}
$$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::pair<T, T> simultaneous_linear_congruence(const std::vector<T>& a, const std::vector<T>& b, const std::vector<T>& m);`|$A_i x \equiv B_i \pmod{M_i}$ を満たす $mk + x$ ($k \in \mathbb{Z},\ 0 \leq x < m$)。ただし存在しないときは $(0, -1)$ を返す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.261-262，マイナビ出版（2012）


## Submissons

https://yukicoder.me/submissions/701737
