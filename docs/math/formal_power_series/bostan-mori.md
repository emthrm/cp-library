# Bostan–Mori のアルゴリズム

$d$-階線形回帰数列の第 $N$ 項を求めるアルゴリズムである。


## 時間計算量

$d$ 次多項式同士の乗算の算術計算量を $\mathsf{M}(d)$ とおくと $O(\mathsf{M}(d) \log{N})$。


## 仕様

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`bostan_mori<多項式, T>(p, q, n)`|${\lbrack x^N \rbrack}\frac{P(x)}{Q(x)}$|${\lbrack x^0 \rbrack}Q = Q(0)$ は可逆元 (invertible element) である。|
|`nth_term_of_linear_recurrence_sequence(a, q, n)`|特性多項式 $Q(x)$ をもち、$A(x) = B(x) \bmod{x^{\mathrm{deg}(A)}}$ を満たす線形回帰数列の母関数 $B(x)$ に対して ${\lbrack x^N \rbrack}B$||


## 参考文献

- http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
- https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
- https://nyaannyaan.github.io/library/fps/kitamasa.hpp
- https://tsuchi.hateblo.jp/entry/2021/10/09/124804


## TODO

- $x^N \bmod \Gamma(x)$
  - https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b


## Submissons

https://judge.yosupo.jp/submission/80098
