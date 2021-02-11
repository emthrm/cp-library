---
title: osa_k 法
documentation_of: math/osa_k.hpp
---

[エラトステネスの篩](sieve_of_eratosthenes.md)を用いた[素因数分解](prime_factorization.md)


## 時間計算量

$\langle O(N\log{\log{N}}), O(\log{N}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`osa_k(n = 10000000)`|$n$ 以下における osa_k 法 を考える．|
|`query(n)`|$n$ の素因数分解|


## 参考

- http://www.osak.jp/diary/diary_201310.html#20131017


## Verified

https://atcoder.jp/contests/abc052/submissions/9301834
