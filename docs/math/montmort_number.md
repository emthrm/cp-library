---
title: モンモール数 (Montmort number)
documentation_of: //include/emthrm/math/montmort_number.hpp
---

$$
  !n =
  \begin{cases}
    1 & (n = 0), \\
    0 & (n = 1), \\
    (n - 1)(!(n - 1) + !(n - 2)) & (n \geq 2)
  \end{cases}
$$

という漸化式をもつ、完全順列の個数 $!n$ である。これを解くと

$$
  !n = n! \sum_{k = 0}^n \dfrac{(-1)^k}{k!}
$$

という一般項が得られる。

指数型母関数は

$$
  \sum_{n = 0}^\infty !n \frac{x^n}{n!} = \dfrac{e^{-x}}{1 - x}
$$

である。


### 完全順列 (complete permutation) / 攪乱順列 (derangement)

大きさ $N$ の順列 $P$ の内、任意の $i \in \lbrace 1, 2, \ldots, N \rbrace$ に対して $P_i \neq i$ を満たすものである。


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> montmort_number(const int n);`|モンモール数 $!i$ ($1 \leq i \leq n$) の数表|


## 参考文献

- Pierre Remond de Montmort: Essay d'analyse sur les jeux de hazard, 2nd edition (1713).
- https://en.wikipedia.org/wiki/Derangement
- https://mathtrain.jp/montmort
- http://kyuridenamida.hatenablog.com/entry/2016/04/27/015414


## Submissons

https://judge.yosupo.jp/submission/2731
