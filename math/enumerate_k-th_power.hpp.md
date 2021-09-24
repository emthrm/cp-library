---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_k-th_power.test.cpp
    title: "\u6570\u5B66/$i^k \\bmod m \\ (0 \\leq i \\leq n)$"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/enumerate_k-th_power.hpp\"\n#include <vector>\r\n#line\
    \ 2 \"math/prime_sieve.hpp\"\n#include <numeric>\r\n#line 4 \"math/prime_sieve.hpp\"\
    \n\r\nstd::vector<int> prime_sieve(int n, bool get_only_prime) {\r\n  std::vector<int>\
    \ prime, smallest_prime_factor(n + 1);\r\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n   \
    \ if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\n    for (int p\
    \ : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i]) break;\r\n\
    \      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\r\n}\r\n#line 2 \"math/mod_pow.hpp\"\n\r\n\
    long long mod_pow(long long base, long long exponent, int mod) {\r\n  base %=\
    \ mod;\r\n  long long res = 1;\r\n  while (exponent > 0) {\r\n    if (exponent\
    \ & 1) (res *= base) %= mod;\r\n    (base *= base) %= mod;\r\n    exponent >>=\
    \ 1;\r\n  }\r\n  return res;\r\n}\r\n#line 5 \"math/enumerate_k-th_power.hpp\"\
    \n\r\nstd::vector<int> enumerate_kth_power(int n, int k, int m) {\r\n  std::vector<int>\
    \ res(n + 1, 0);\r\n  std::vector<int> smallest_prime_factor = prime_sieve(n,\
    \ false);\r\n  for (int i = 1; i <= n; ++i) {\r\n    if (smallest_prime_factor[i]\
    \ == i) {\r\n      res[i] = mod_pow(i, k, m);\r\n    } else {\r\n      res[i]\
    \ = static_cast<long long>(res[smallest_prime_factor[i]]) * res[i / smallest_prime_factor[i]]\
    \ % m;\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"prime_sieve.hpp\"\r\n#include\
    \ \"mod_pow.hpp\"\r\n\r\nstd::vector<int> enumerate_kth_power(int n, int k, int\
    \ m) {\r\n  std::vector<int> res(n + 1, 0);\r\n  std::vector<int> smallest_prime_factor\
    \ = prime_sieve(n, false);\r\n  for (int i = 1; i <= n; ++i) {\r\n    if (smallest_prime_factor[i]\
    \ == i) {\r\n      res[i] = mod_pow(i, k, m);\r\n    } else {\r\n      res[i]\
    \ = static_cast<long long>(res[smallest_prime_factor[i]]) * res[i / smallest_prime_factor[i]]\
    \ % m;\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/prime_sieve.hpp
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/enumerate_k-th_power.hpp
  requiredBy: []
  timestamp: '2021-03-15 23:21:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_k-th_power.test.cpp
documentation_of: math/enumerate_k-th_power.hpp
layout: document
title: $i^k \bmod m \ (0 \leq i \leq n)$
---


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`enumerate_kth_power(n, k, m)`|$i^k \bmod m \ (0 \leq i \leq n)$|


## 参考

- https://37zigen.com/linear-sieve/


## Verified

https://yukicoder.me/submissions/623345
