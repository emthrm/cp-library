# 第2種スターリング数 (Stirling number of the second kind)

$$x^n = \sum_{k = 0}^n S(n, k) x^{\underline{k}}$$

で定義される $S$ である．

$$\begin{aligned} S(n, k) = \begin{cases} 1 & (n = k) \\ 0 & (n \geq 1,\ k = 0) \\ S(n-1, k-1) + k S(n-1, k) & (1 \leq k < n) \end{cases} \end{aligned}$$

なる漸化式より計算ができる．

一般項は

$$S(n,k) = \dfrac{\sum_{i = 1}^k (-1)^{k - i} \binom{k}{i} i^n}{k!}$$

である．

組合せ数学においては区別された $n$ 個を $k$ グループに分割する個数を意味する．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(K\log{N})$|
|数表|$O(NK)$|
|数表 形式的冪級数版|$O(N\log{N})$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`stirling_number_of_the_second_kind(n, k, Combinatorics)`|第2種スターリング数 $S(n,k)$|`Combinatorics` は $k$ 以上で定義されていなければならない．|

- 数表

||説明|
|:--:|:--:|
|`stirling_number_of_the_second_kind_init<T>(n, k)`|第2種スターリング数 $S(i, j) \ (0 \leq i \leq n,\ 0 \leq j \leq k)$ の数表|

- 数表 形式的冪級数版

||説明|備考|
|:--:|:--:|:--:|
|`stirling_number_of_the_second_kind_init_with_fps(n, Combinatorics)`|第2種スターリング数 $S(n, k) \ (0 \leq k \leq n)$ の数表|`Combinatorics` は $n$ 以上で定義されていなければならない．|


## 参考

- https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0
- https://mathtrain.jp/stnum
- https://mathtrain.jp/zensya
- 数表 形式的冪級数版
  - https://min-25.hatenablog.com/entry/2015/04/07/160154


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088846/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088857/emthrm/C++14)
- [数表 形式的冪級数版](https://judge.yosupo.jp/submission/4636)
