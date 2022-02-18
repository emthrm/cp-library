---
title: 商の列挙
documentation_of: math/enumerate_quotients.hpp
---


## 時間計算量

$O(\sqrt{N})$


## 使用法

||説明|
|:--:|:--:|
|`enumerate_quotients(n)`|$\lbrace (l, r, q) \mid \forall x \in \lbrace l, l + 1, \ldots, r - 1 \rbrace,\ \lfloor \frac{n}{x} \rfloor = q \rbrace$|


## 参考

- https://twitter.com/noshi91/status/1278227768333852672


## Verified

https://atcoder.jp/contests/abc230/submissions/28839379
