---
title: [
  第1種スターリング数 (Stirling number of the first kind) の数表,
  第1種スターリング数 (Stirling number of the first kind) の数表 形式的冪級数版,
  第2種スターリング数 (Stirling number of the second kind),
  第2種スターリング数 (Stirling number of the second kind) の数表,
  第2種スターリング数 (Stirling number of the second kind) の数表 形式的冪級数版
]
documentation_of: [
  //include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init.hpp,
  //include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_by_fps.hpp,
  //include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp,
  //include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp,
  //include/emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
]
---

# スターリング数 (Stirling number)


## 第1種スターリング数 (Stirling number of the first kind)

$$
  x^{\overline{n}} = \sum_{k = 0}^n s(n, k) x^k
$$

で定義される $s$ である。

$$
  \begin{aligned}
    s(n, k) =
    \begin{cases}
      1 & (n = k), \\
      0 & (n \geq 1,\ k = 0), \\
      s(n - 1, k - 1) + (n - 1)s(n - 1, k) & (1 \leq k < n)
    \end{cases}
  \end{aligned}
$$

という漸化式をもつ。

組合せ数学では区別された $n$ 個を $k$ 個の巡回列に分割する個数を意味する。


## 第2種スターリング数 (Stirling number of the second kind)

$$
  x^n = \sum_{k = 0}^n S(n, k) x^{\underline{k}}
$$

で定義される $S$ である。

$$
  \begin{aligned}
    S(n, k) =
    \begin{cases}
      1 & (n = k), \\
      0 & (n \geq 1,\ k = 0), \\
      S(n-1, k-1) + k S(n - 1, k) & (1 \leq k < n)
    \end{cases}
  \end{aligned}
$$

という漸化式をもつ。

一般項は

$$
  S(n,k) = \dfrac{\sum_{i = 1}^k (-1)^{k - i} \binom{k}{i} i^n}{k!}
$$

である。

組合せ数学では区別された $n$ 個を $k$ グループに分割する個数を意味する。


## 時間計算量

||時間計算量|
|:--|:--|
|第1種スターリング数の数表|$O(NK)$|
|第1種スターリング数の数表 形式的冪級数版|$O(N\log{N})$|
|第2種スターリング数|$O(K\log{N})$|
|第2種スターリング数の数表|$O(NK)$|
|第2種スターリング数の数表 形式的冪級数版|$O(N\log{N})$|


## 仕様

### 第1種スターリング数の数表

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> stirling_number_of_the_first_kind_init(const int n, const int k);`|第1種スターリング数 $s(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|


### 第1種スターリング数の数表 形式的冪級数版

|名前|戻り値|備考|
|:--|:--|:--|
|`template <typename T>`<br>`std::vector<T> stirling_number_of_the_first_kind_init_by_fps(const int n);`|第1種スターリング数 $s(n, k)$ ($0 \leq k \leq n$) の数表|$x^{\underline{n}} = \sum_{k = 0}^n (-1)^{n + k} s(n, k) x^k$|


### 第2種スターリング数

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`MInt<T> stirling_number_of_the_second_kind(const int n, const int k);`|第2種スターリング数 $S(n,k)$|


### 第2種スターリング数の数表

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> stirling_number_of_the_second_kind_init(const int n, const int k);`|第2種スターリング数 $S(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq k$) の数表|


### 第2種スターリング数の数表 形式的冪級数版

|名前|戻り値|
|:--|:--|
|`template <int T>`<br>`std::vector<MInt<T>> stirling_number_of_the_second_kind_init_by_fps(const int n);`|第2種スターリング数 $S(n, k)$ ($0 \leq k \leq n$) の数表|


## 参考文献

- https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0

第2種スターリング数
- https://mathtrain.jp/stnum
- https://mathtrain.jp/zensya

形式的冪級数版
- https://min-25.hatenablog.com/entry/2015/04/07/160154


## TODO

- 小さな素数 $p \in \mathbb{P}$ で割ったあまり
  - https://maspypy.com/stirling-%e6%95%b0%e3%82%92-p-%e3%81%a7%e5%89%b2%e3%81%a3%e3%81%9f%e4%bd%99%e3%82%8a%e3%81%ae%e8%a8%88%e7%ae%97
  - https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_small_p_large_n
  - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n


## Submissons

- 第1種スターリング数の数表
- [第1種スターリング数の数表 形式的冪級数版](https://judge.yosupo.jp/submission/4637)
- [第2種スターリング数](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088846/emthrm/C++14)
- [第2種スターリング数の数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088857/emthrm/C++14)
- [第2種スターリング数の数表 形式的冪級数版](https://judge.yosupo.jp/submission/4636)
