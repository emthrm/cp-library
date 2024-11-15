---
title: [
  ベル数 (Bell number),
  ベル数 (Bell number) の数表,
  ベル数 (Bell number) の数表 $n = k$ 版
]
documentation_of: [
  //include/emthrm/math/twelvefold_way/bell_number/bell_number.hpp,
  //include/emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp,
  //include/emthrm/math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp
]
---

# ベル数 (Bell number)

区別された $n$ 個を $k$ グループ以下に分割する場合の数を $B(n, k)$ とおくと

$$
  B(n,k) = \sum_{j = 0}^k S(n, j) = \sum_{i = 0}^k \frac{i^n}{i!} \sum_{j = 0}^{k - i} \frac{(-1)^j}{j!}
$$

が成り立つ。ここで $S$ は[第2種スターリング数](../stirling_number/stirling_number.md)である。

$n = k$ を満たす $B(n, k)$ をベル数 $B_n$ と呼ぶ。

漸化式は

$$
  B_{n + 1} = \sum_{k = 0}^n \binom{n}{k} B_k
$$

であり、指数型母関数は

$$
  \sum_{n = 0}^\infty B_n \frac{x^n}{n!} = e^{e^x - 1}
$$

である。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(\min \lbrace N, K \rbrace \log{N})$|
|数表|$O(NK)$|
|数表 $n = k$ 版|$O(N\log{N})$|


## 仕様

|名前|戻り値|
|:--|:--|
|`template <unsigned int T>`<br>`MInt<T> bell_number(const int n, int k);`|$B(n, k)$|


### 数表

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> bell_number_init(const int n, const int k);`|$B(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|


### 数表 $n = k$ 版

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> bell_number_init_by_fps(const int n);`|ベル数 $B_i$ ($0 \leq i \leq n$) の数表|


## 参考文献

- Eric Temple Bell: The Iterated Exponential Integers, *Annals of Mathematics*, Vol. 39, No. 3, pp. 539–557 (1938). https://doi.org/10.2307/1968633
- H. W. Becker and John Riordan: The Arithmetic of Bell and Stirling Numbers, *American Journal of Mathematics*, Vol. 70, No. 2, pp. 385–394 (1948). https://doi.org/10.2307/2372336
- https://ja.wikipedia.org/wiki/ベル数
- https://qiita.com/drken/items/f2ea4b58b0d21621bd51


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088882/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_G/review/4088892/emthrm/C++14)
- [数表 $n = k$ 版](https://judge.yosupo.jp/submission/249770)
