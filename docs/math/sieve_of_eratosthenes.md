---
title: エラトステネスの篩 (sieve of Eratosthenes)
documentation_of: math/sieve_of_eratosthenes.hpp
---

素数を列挙するアルゴリズムである．


## 時間計算量

$O(N\log{\log{N}})$


## 使用法

||説明|
|:--:|:--:|
|`sieve_of_eratosthenes(n)`|$i \ (0 \leq i \leq \mathrm{n})$ が素数であるか．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.111-112


## ToDo

- $O(N)$ に高速化する．
  - https://37zigen.com/linear-sieve/
  - https://codeforces.com/blog/entry/66586
  - https://imulan.hatenablog.jp/entry/2019/09/29/212808
  - https://judge.yosupo.jp/problem/enumerate_primes
- $n$ 以下の素数の個数
  - http://sugarknri.hatenablog.com/entry/2019/07/31/102422
  - https://judge.yosupo.jp/problem/counting_primes


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0009/review/4088022/emthrm/C++14
