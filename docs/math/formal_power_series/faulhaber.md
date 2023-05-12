---
title: [
  ファウルハーバーの公式 (Faulhaber's formula) 形式的冪級数版,
  ファウルハーバーの公式 (Faulhaber's formula) ラグランジュ補間版
]
documentation_of: [
  //include/emthrm/math/formal_power_series/faulhaber_by_fps.hpp,
  //include/emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
]
---

# ファウルハーバーの公式 (Faulhaber's formula)

$$
  S_k(n) \mathrel{:=} \sum_{i = 1}^{n - 1} i^k
$$

と定義すると

$$
  S_k(n + 1) = \dfrac{1}{k + 1} \sum_{i = 0}^k \binom{k + 1}{i} B_i n^{k + 1 - i}
$$

が成り立つ。ここで $B$ は[ベルヌーイ数](bernoulli_number)である。


## 時間計算量

||時間計算量|
|:--|:--|
|形式的冪級数版|$O(K\log{K})$|
|ラグランジュ補間版|$O(K \log{\max{\lbrace K, M \rbrace}})$|


## 仕様

### 形式的冪級数版

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> faulhaber_by_fps(const long long n, const int k);`|$S_k(n)$|


### ラグランジュ補間版

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> faulhaber_by_lagrange_interpolation(const long long n, const int k);`|$S_k(n)$|


## 参考文献

- Jacob Bernoulli: Ars Conjectandi (1713).
- https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F


## Submissons

- [形式的冪級数版](https://yukicoder.me/submissions/431468)
- [ラグランジュ補間版](https://yukicoder.me/submissions/437458)
