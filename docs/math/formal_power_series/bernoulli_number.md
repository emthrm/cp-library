---
title: ベルヌーイ数 (Bernoulli number)
documentation_of: //include/emthrm/math/formal_power_series/bernoulli_number.hpp
---

$$
  \dfrac{x}{e^x - 1} = \sum_{n = 0}^{\infty} B_n \frac{x^n}{n!}
$$

で定義される $B_n$ である。

$$
  \begin{cases}
    B_0 = 1, \\
    B_n = -\dfrac{1}{n + 1} \sum_{k = 0}^{n - 1} \binom{n + 1}{k} B_k
  \end{cases}
$$

という漸化式をもつ。


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> bernoulli_number(const int n);`|ベルヌーイ数 $B_i$ ($0 \leq i \leq n$) の数表|


## 参考文献

- Jacob Bernoulli: Ars Conjectandi (1713).
- https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0


## Submissons

https://judge.yosupo.jp/submission/3792
