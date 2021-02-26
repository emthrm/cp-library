---
title: osa_k 法
documentation_of: math/osa_k.hpp
---

[prime sieve](prime_sieve.md) を用いた[素因数分解](prime_factorization.md)である．


## 時間計算量

$\langle O(N), O(\log{N}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`smallest_prime_factor[i]`|$i$ の最小素因数|
|`osa_k(n = 10000000)`|$n$ 以下における osa_k 法を考える．|
|`query(n)`|$n$ の素因数分解|


## 参考

- http://www.osak.jp/diary/diary_201310.html#20131017


## Verified

https://atcoder.jp/contests/abc177/submissions/20504644
