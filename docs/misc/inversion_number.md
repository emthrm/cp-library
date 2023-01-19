---
title: 転倒数 (inversion number)
documentation_of: include/emthrm/misc/inversion_number.hpp
---

数列 $A$ に対して $A_i > A_j$ を満たす組 $(i, j)$ ($i < j$) の個数である。

バブルソートに必要な交換回数に等しい。


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T> long long inversion_number(const std::vector<T>& a);`|$A$ の転倒数|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.162-163，マイナビ出版（2012）


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_5_D/review/4087800/emthrm/C++14
