---
title: 多項式列の相乗
documentation_of: include/emthrm/math/formal_power_series/product_of_polynomial_sequence.hpp
---

$$
  \prod_i f_i(x)
$$


## 仕様

|名前|戻り値|備考|
|:--|:--|:--|
|`template <template <typename> class C, typename T> C<T> product_of_polynomial_sequence(std::vector<C<T>> a);`|$\prod_i f_i(x)$|`C` は冪級数を表す構造体である。|


## Submissons

https://judge.yosupo.jp/submission/113024
