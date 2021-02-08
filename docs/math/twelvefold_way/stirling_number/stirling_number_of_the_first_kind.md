# 第1種スターリング数 (Stirling number of the first kind)

$$x^{\overline{n}} = \sum_{k = 0}^n s(n, k) x^k$$

で定義される $s$ である．

$$\begin{aligned} s(n, k) = \begin{cases} 1 & (n = k) \\ 0 & (n \geq 1,\ k = 0) \\ s(n - 1, k - 1) + (n - 1)s(n - 1, k) & (1 \leq k < n) \end{cases} \end{aligned}$$

なる漸化式より計算ができる．

組合せ数学においては区別された $n$ 個を $k$ 個の巡回列に分割する個数を意味する．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(NK)$|
|形式的冪級数版|$O(N\log{N})$|
|形式的冪級数版2|$O(N(\log{N})^2)$|


## 使用法

||説明|
|:--:|:--:|
|`stirling_number_of_the_first_kind_init<T>(n, k)`|第1種スターリング数 $s(i, j) \ (0 \leq i \leq n,\ 0 \leq j \leq k)$ の数表|

- 形式的冪級数版

||説明|備考|
|:--:|:--:|:--:|
|`stirling_number_of_the_first_kind_init_with_fps<T>(n)`|第1種スターリング数 $s(n, k) \ (0 \leq k \leq n)$ の数表|$x^{\underline{n}} = \sum_{k = 0}^n s(n, k) x^k$|

- 形式的冪級数版2

||説明|備考|
|:--:|:--:|:--:|
|`stirling_number_of_the_first_kind_init_with_fps2<T>(n)`|第1種スターリング数 $s(n, k) \ (0 \leq k \leq n)$ の数表|$x^{\underline{n}} = \sum_{k = 0}^n s(n, k) x^k$|


## 参考

- https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0
- 形式的冪級数版
  - https://min-25.hatenablog.com/entry/2015/04/07/160154

## ToDo

- https://github.com/ei1333/library/blob/master/math/fps/formal-power-series-seq.cpp


## Verified

- []()
- [形式的冪級数版](https://judge.yosupo.jp/submission/4637)
- [形式的冪級数版2](https://judge.yosupo.jp/submission/4638)
