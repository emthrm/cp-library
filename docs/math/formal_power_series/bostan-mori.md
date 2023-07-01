---
title: [
  Bostan–Mori のアルゴリズム,
  線形回帰数列 (linear recurrence sequence) の第 $N$ 項
]
documentation_of: [
  //include/emthrm/math/formal_power_series/bostan-mori.hpp,
  //include/emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
]
---

# Bostan–Mori のアルゴリズム

$d$-階線形回帰数列の第 $N$ 項を求めるアルゴリズムである。


## 時間計算量

$d$ 次多項式同士の乗算の算術計算量を $\mathsf{M}(d)$ とおくと $O(\mathsf{M}(d) \log{N})$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename T>`<br>`T bostan_mori(FormalPowerSeries<T> p, FormalPowerSeries<T> q, long long n);`|${\lbrack x^N \rbrack}\frac{P(x)}{Q(x)}$|${\lbrack x^0 \rbrack}Q = Q(0)$ は可逆元 (invertible element) である。|
|`template <typename T>`<br>`T nth_term_of_linear_recurrence_sequence(FormalPowerSeries<T> a, FormalPowerSeries<T> q, const long long n);`|特性多項式 $Q(x)$ をもち、$A(x) = B(x) \bmod{x^{\mathrm{deg}(A) + 1}}$ を満たす線形回帰数列の母関数 $B(x)$ に対して ${\lbrack x^N \rbrack}B$||


## 参考文献

- http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
- https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
- https://nyaannyaan.github.io/library/fps/kitamasa.hpp
- https://tsuchi.hateblo.jp/entry/2021/10/09/124804


## TODO

- https://noshi91.hatenablog.com/entry/2023/03/29/215553
- $x^N \bmod \Gamma(x)$
  - https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b
- 高速化
  - https://twitter.com/noya2ruler/status/1654157396627927042


## Submissons

https://judge.yosupo.jp/submission/80098
