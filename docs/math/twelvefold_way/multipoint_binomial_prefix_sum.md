---
title: 二項係数の prefix sum の多点評価
documentation_of: //include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp
---

$Q$ 個のクエリ $(n_i, m_i)$ に対して

$$
  \sum_{k = 0}^{m_i} \binom{n_i}{k}
$$

を求める。


## 時間計算量

$N \mathrel{:=} \max_i n_i$ とおくと $O(Q\log{Q} + N\sqrt{Q})$


## 仕様

|名前|戻り値|制約|
|:--|:--|:--|
|`template <unsigned int T>`<br>`std::vector<MInt<T>> multipoint_binomial_prefix_sum(const std::vector<int>& ns, const std::vector<int>& ms);`|$\sum_{k = 0}^{\mathrm{ms}_i} \binom{\mathrm{ns}_i}{k}$|$T$ は奇数である。<br>$0 \leq \mathrm{ms}_i \leq \mathrm{ns}_i$|


## アルゴリズム

$$
  S(n, m) \mathrel{:=} \sum_{k = 0}^{m} \binom{n}{k}
$$

とおくと以下がすべて成り立つ。

- $S(n, m - 1) = S(n, m) - \binom{n}{m}$
- $S(n, m + 1) = S(n, m) + \binom{n}{m + 1}$
- $S(n + 1, m) = \sum_{k = 0}^m (\binom{n}{k - 1} + \binom{n}{k}) = 2S(n, m) - \binom{n}{m}$
- $S(n - 1, m) = (S(n, m) + \binom{n - 1}{m}) / 2$

よって各クエリを区間 $[m_i, n_i)$ とみなせば Mo's algorithm が適用できる。


## 参考文献

- https://x.com/SSRS_cp/status/1878443555716473092
- https://x.com/noshi91/status/1349778791262945280


## Submissons

https://yukicoder.me/submissions/1190011
