---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/osa_k.test.cpp
    title: "\u6570\u5B66/osa_k \u6CD5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/osa_k.hpp\"\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"math/prime_sieve.hpp\"\n#include <numeric>\n#line 4 \"math/prime_sieve.hpp\"\
    \n\nstd::vector<int> prime_sieve(const int n, const bool get_only_prime) {\n \
    \ std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) prime.emplace_back(i);\n    for (const int p : prime) {\n      if (i *\
    \ p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return get_only_prime ? prime : smallest_prime_factor;\n\
    }\n#line 6 \"math/osa_k.hpp\"\n\nstruct OsaK {\n  const std::vector<int> smallest_prime_factor;\n\
    \n  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve(n, false))\
    \ {}\n\n  std::vector<std::pair<int, int>> query(int n) const {\n    std::vector<std::pair<int,\
    \ int>> res;\n    while (n > 1) {\n      const int prime = smallest_prime_factor[n];\n\
    \      int exponent = 0;\n      for (; smallest_prime_factor[n] == prime; n /=\
    \ prime) {\n        ++exponent;\n      }\n      res.emplace_back(prime, exponent);\n\
    \    }\n    return res;\n  }\n};\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\n#include \"./prime_sieve.hpp\"\
    \n\nstruct OsaK {\n  const std::vector<int> smallest_prime_factor;\n\n  explicit\
    \ OsaK(const int n) : smallest_prime_factor(prime_sieve(n, false)) {}\n\n  std::vector<std::pair<int,\
    \ int>> query(int n) const {\n    std::vector<std::pair<int, int>> res;\n    while\
    \ (n > 1) {\n      const int prime = smallest_prime_factor[n];\n      int exponent\
    \ = 0;\n      for (; smallest_prime_factor[n] == prime; n /= prime) {\n      \
    \  ++exponent;\n      }\n      res.emplace_back(prime, exponent);\n    }\n   \
    \ return res;\n  }\n};\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: false
  path: math/osa_k.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/osa_k.test.cpp
documentation_of: math/osa_k.hpp
layout: document
title: "osa_k \u6CD5"
---

[prime sieve](prime_sieve.md) を用いた[素因数分解](prime_factorization.md)である．


## 時間計算量

$\langle O(N), O(\log{N}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`smallest_prime_factor[i]`|$i$ の最小素因数|
|`OsaK(n)`|$n$ 以下における osa_k 法を考える．|
|`query(n)`|$n$ の素因数分解|


## 参考

- http://www.osak.jp/diary/diary_201310.html#20131017


## Verified

https://atcoder.jp/contests/abc177/submissions/20504644
