---
title: osa_k 法
documentation_of: include/emthrm/math/osa_k.hpp
---

[prime sieve](prime_sieve.md) を用いた[素因数分解](prime_factorization.md)である。


## 時間計算量

$\langle O(N), O(\log{N}) \rangle$


## 仕様

|名前|効果・戻り値|
|:--|:--|
|`smallest_prime_factor[i]`|$i$ の最小素因数|
|`OsaK(n)`|$n$ 以下における osa_k 法を考える。|
|`query(n)`|$n$ の素因数分解|


## 参考文献

- http://www.osak.jp/diary/diary_201310.html#20131017


## Submissons

https://atcoder.jp/contests/abc177/submissions/20504644
