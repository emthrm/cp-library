---
title: カタラン数 (Catalan number)
documentation_of: //include/emthrm/math/catalan_number.hpp
---

$$
  c_n \mathrel{:=} \dfrac{\binom{2n}{n}}{n + 1} = \dbinom{2n}{n} - \dbinom{2n}{n - 1}
$$

で定義される $c$ である。

$$
  \begin{cases}
    c_0 = 1, \\
    c_{n + 1} = \sum_{i = 0}^n c_i c_{n - i}
  \end{cases}
$$

の特殊解である。

カタラン数 $c_n$ を適用できる例として以下がある。
- 長さ $2n$ の correct bracket sequence の場合の数
- $n \times n$ マスの格子で左下から右上まで対角線をまたがない最短経路の個数
- $n + 1$ 個の葉を持つ二分木の個数
- $n + 1$ 人によるトーナメントの総数
- 凸 $n + 2$ 角形の三角形分割の個数


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <unsigned int T>`<br>`std::vector<MInt<T>> catalan_number(const int n);`|カタラン数 $c_i$ ($0 \leq i \leq n$) の数表|


## 参考文献

- https://mathtrain.jp/catalan
- https://noshi91.hatenablog.com/entry/2021/07/10/170943
- https://ei1333.hateblo.jp/entry/2021/12/10/175837
- https://drive.google.com/file/d/1WC7Y2Ni-8elttUgorfbix9tO1fvYN3g3


## Submissons

https://yukicoder.me/submissions/414045
