---
title: 繰り返し二乗法 / 二分累乗法 / バイナリ法
documentation_of: //include/emthrm/math/mod_pow.hpp
---

累乗を高速に求めるアルゴリズムである。


## 時間計算量

$O(\log{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`long long mod_pow(long long x, long long n, const int m);`|$x^n \bmod{m}$|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.114-116，マイナビ出版（2012）


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_B/review/4088294/emthrm/C++14
