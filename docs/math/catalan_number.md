---
title: カタラン数 (Catalan number)
documentation_of: math/catalan_number.hpp
---

$$c_n = \dfrac{\binom{2n}{n}}{n + 1} = \dbinom{2n}{n} - \dbinom{2n}{n - 1}$$

で定義された $c$ である．

$$\begin{cases} c_0 = 1 \\ c_{n + 1} = \sum_{i = 0}^n c_i c_{n - i} \end{cases}$$

の特殊解である．

カタラン数 $c_n$ の適用可能な例
- 長さ $2n$ の correct bracket sequence の場合の数
- $n \times n$ マスの格子において左下から右上まで対角線をまたがない最短経路の個数
- $n + 1$ 個の葉を持つ二分木の個数
- $n + 1$ 人によるトーナメントの総数
- 凸 $n + 2$ 角形の三角形分割の個数


## 時間計算量

$O(N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`catalan_number(n, Combinatorics)`|カタラン数 $c_i \ (0 \leq i \leq n)$ の数表|`Combinatorics` は $n + 1$ 以上で定義されていなければならない．|


## 参考

- https://mathtrain.jp/catalan
- https://drive.google.com/file/d/1WC7Y2Ni-8elttUgorfbix9tO1fvYN3g3/view
- https://tubo28.me/compprog/algorithm/catalan-number/


## Verified

https://yukicoder.me/submissions/414045
