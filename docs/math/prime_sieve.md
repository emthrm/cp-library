---
title: prime sieve
documentation_of: //include/emthrm/math/prime_sieve.hpp
---


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <bool GETS_ONLY_PRIME> std::vector<int> prime_sieve(const int n);`|$n$ 以下の素数または $i$ ($i \leq n$) の最小素因数|


## 参考文献

- https://37zigen.com/linear-sieve/
- https://imulan.hatenablog.jp/entry/2019/09/29/212808


## TODO

- $n$ 以下の素数の個数
  - ~~http://sugarknri.hatenablog.com/entry/2019/07/31/102422~~
  - https://rsk0315.hatenablog.com/entry/2021/05/18/015511
  - https://rsk0315.github.io/slides/prime-counting.pdf
  - https://suu-0313.hatenablog.com/entry/2021/09/14/225759
  - https://sotanishy.github.io/cp-library-cpp/math/prime_count.hpp
  - https://judge.yosupo.jp/problem/counting_primes


## Submissons

https://yukicoder.me/submissions/623330
