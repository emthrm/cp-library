---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/osa_k.test.cpp
    title: "\u6570\u5B66/osa_k \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/osa_k.hpp\"\n#include <utility>\r\n#include <vector>\r\
    \n\r\n#line 2 \"math/prime_sieve.hpp\"\n#include <numeric>\r\n#line 4 \"math/prime_sieve.hpp\"\
    \n\r\nstd::vector<int> prime_sieve(const int n, const bool get_only_prime) {\r\
    \n  std::vector<int> smallest_prime_factor(n + 1), prime;\r\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n   \
    \ if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\n    for (const\
    \ int p : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i]) break;\r\
    \n      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\r\n}\r\n#line 6 \"math/osa_k.hpp\"\n\r\nstruct\
    \ OsaK {\r\n  const std::vector<int> smallest_prime_factor;\r\n\r\n  explicit\
    \ OsaK(const int n) : smallest_prime_factor(prime_sieve(n, false)) {}\r\n\r\n\
    \  std::vector<std::pair<int, int>> query(int n) const {\r\n    std::vector<std::pair<int,\
    \ int>> res;\r\n    while (n > 1) {\r\n      const int prime = smallest_prime_factor[n];\r\
    \n      int exponent = 0;\r\n      for (; smallest_prime_factor[n] == prime; n\
    \ /= prime) {\r\n        ++exponent;\r\n      }\r\n      res.emplace_back(prime,\
    \ exponent);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <utility>\r\n#include <vector>\r\n\r\n#include \"\
    ./prime_sieve.hpp\"\r\n\r\nstruct OsaK {\r\n  const std::vector<int> smallest_prime_factor;\r\
    \n\r\n  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve(n, false))\
    \ {}\r\n\r\n  std::vector<std::pair<int, int>> query(int n) const {\r\n    std::vector<std::pair<int,\
    \ int>> res;\r\n    while (n > 1) {\r\n      const int prime = smallest_prime_factor[n];\r\
    \n      int exponent = 0;\r\n      for (; smallest_prime_factor[n] == prime; n\
    \ /= prime) {\r\n        ++exponent;\r\n      }\r\n      res.emplace_back(prime,\
    \ exponent);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: false
  path: math/osa_k.hpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
