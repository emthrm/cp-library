---
title: 素数判定 (primality test)
documentation_of: //include/emthrm/math/is_prime.hpp
---


## 時間計算量

$O(\sqrt{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`bool is_prime(const long long n);`|$n$ は素数であるか。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.110-111，マイナビ出版（2012）


## TODO

- https://www.slideshare.net/DEGwer/ss-14119074
- https://qiita.com/srtk86/items/609737d50c9ef5f5dc59
- ミラー-ラビン素数判定法 (Miller–Rabin primality test)
  - https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95
  - https://drken1215.hatenablog.com/entry/2023/05/23/233000
  - https://qiita.com/zu_rin/items/25521b5870389e0f85bf
  - http://joisino.hatenablog.com/entry/2017/08/03/210000
  - ~~http://www.prefield.com/algorithm/math/isprime.html~~
  - https://tubo28.me/compprog/algorithm/miller-rabin/
  - https://sotanishy.github.io/cp-library-cpp/math/fast_prime.cpp
  - https://yukicoder.me/problems/1967
  - https://judge.yosupo.jp/problem/primarity_test


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_1_C/review/4088317/emthrm/C++14
